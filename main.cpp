#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    // element ,  element-index
    int idx1{}, idx2{};
    auto process_and_lookup([m = std::unordered_map<int, int>(),
                                i = 0,
                                target,
                                &idx1, &idx2](const auto item) mutable {
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
  }
};

int main() {
  auto input = std::vector({3, 2, 4});
  auto v = Solution::twoSum(input, 6);
  std::cout << "sz " << v.size() << '\n';
  std::cout << v[0] << ',' << v[1] << '\n';
}
