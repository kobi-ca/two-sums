#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // element ,  <diff, element-index>
        std::multimap<int, std::pair<int, int>> m;
        (void)std::transform(cbegin(nums), cend(nums), std::inserter(m, end(m)),
                             [i=0, target] (const auto item) mutable {
            std::cout << "item " << item << " insert " << target - item << " index " << (i) << '\n';
            auto value = std::make_pair(target - item, i++);
            return std::make_pair(item, value);
        });
        for(const auto& [k, v] : m) {
            auto [diff, idx] = v;
            auto [iter1, iter2] = m.equal_range(diff);
            std::cout << "k " << k << " diff " << diff << '\n';
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
    }
};

int main() {
    Solution s;
    auto input = std::vector({3, 2, 4});
    auto v = s.twoSum(input, 6);
    std::cout << "sz " << v.size() << '\n';
    std::cout << v[0] << ',' << v[1] << '\n';
}