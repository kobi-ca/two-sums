#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

class Solution {
public:
    static std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
        // element ,  element-index
        std::map<int, int> m;
        int idx1{}, idx2{};
        auto process_and_lookup([i = 0, target, &m, &idx1, &idx2](const auto item) mutable {
            auto iter = m.find(target - item);
            if(iter == cend(m)) {
                m[item] = i++;
                return false;
            }
            idx1 = iter->second;
            idx2 = i;
            return true;
        });
        auto iter = std::find_if(cbegin(nums), cend(nums), process_and_lookup);
        assert(iter != cend(nums));
        return {idx1, idx2};
        /*
        (void) std::transform(cbegin(nums), cend(nums), std::inserter(m, end(m)), int_to_map);
        for (const auto &[k, v] : m) {
            auto [diff, idx] = v;
            auto [iter1, iter2] = m.equal_range(diff);
            if (iter1 == end(m)) {
                continue;
            }
            if (iter1->first != diff) {
                continue;
            }
            if (1 == std::distance(iter1, iter2)) {
                return std::vector{idx, iter1->second.second};
            }
            auto idx1 = iter1->second.second;
            auto idx2 = std::next(iter1)->second.second;
            return std::vector{idx1, idx2};
        }
        return {};
         */
    }
};

int main() {
    auto input = std::vector({3, 2, 4});
    auto v = Solution::twoSum(input, 6);
    std::cout << "sz " << v.size() << '\n';
    std::cout << v[0] << ',' << v[1] << '\n';
}
