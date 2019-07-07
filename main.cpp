#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/reshape-the-matrix/


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (r <= 0 || c <= 0 || nums.size() == 0) return nums;
        int maxrow = nums.size() - 1;
        int maxcol = nums[0].size() - 1;
        if (r * c != (maxrow + 1) * (maxcol + 1)) return nums;
        vector<vector<int>> matrix(r);
        for (auto &v : matrix)
            v.resize(c);
        int row = 0;
        int col = 0;
        for (int i = 0; i <= r && row <= maxrow; ++i) {
            for (int j = 0; j < c && row <= maxrow; ++j) {
                matrix[i][j] = nums[row][col];
                ++col;
                if (col > maxcol) {
                    col = 0;
                    ++row;
                }
            }
        }
        if (row == maxrow + 1 && col == 0)
            return matrix;
        return nums;
    }
};

void test1() {
    vector<vector<int>> v1{vector<int>{1, 2}, vector<int>{3, 4}};

    cout << "[1,2,3,4] ? " << Solution().matrixReshape(v1, 1, 4) << endl;

    cout << "[1][2][3][4] ? " << Solution().matrixReshape(v1, 4, 1) << endl;
}

void test2() {

}

void test3() {

}