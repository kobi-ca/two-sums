#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
        // element ,  <diff, element-index>
        std::multimap<int, int> m;
        auto transform_func([i = 0, target](const auto item) mutable {
            return std::make_pair(item, i++);
        });

        (void) std::transform(cbegin(nums), cend(nums), std::inserter(m, end(m)), transform_func);
        int idx1{}, idx2{};
        auto find_func([&m, i = 0, target, &idx1, &idx2](const auto item) mutable {
            const auto diff = target - item;
            auto [iter1, iter2] = m.equal_range(diff);
            if (iter1 == end(m) || iter1->first != diff) {
                ++i;
                return false;
            }
            if (1 == std::distance(iter1, iter2)) {
                if (iter1->second == i) {
                    ++i;
                    return false;
                }
                idx1 = i;
                idx2 = iter1->second;
                if (idx1 > idx2) {
                    std::swap(idx1, idx2);
                }
                return true;
            }
            idx1 = iter1->second;
            idx2 = std::next(iter1)->second;
            if (idx1 > idx2) {
                std::swap(idx1, idx2);
            }
            return true;
        });
        auto iter = std::find_if(cbegin(nums), cend(nums), find_func);
        assert(iter != cend(nums));
        return {idx1, idx2};
    }
};

int main() {
    auto input = std::vector({3, 3});
    auto v = Solution::twoSum(input, 6);
    std::cout << "sz " << v.size() << '\n';
    std::cout << v[0] << ',' << v[1] << '\n';
}
