#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem;
        vector<int> tmp;

        for(int j = 0; j < grid[0].size(); j++){
            tmp.push_back(-1);
        }

        for(int i = 0; i < grid.size(); i++){
            mem.push_back(tmp);
        }

        return traverse(0, 0, grid, mem);
    }

    //recursive check every path
    int traverse(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& mem){
        if(x < grid[0].size() && x > -1 && y < grid.size() && y > -1){

            if(mem[y][x] != -1){
                return mem[y][x];
            }

            int right = traverse(x+1, y, grid, mem);
            int down = traverse(x, y + 1, grid, mem);

            if(right == -1 && down == -1){
                mem[y][x] = grid[y][x];
                return grid[y][x];
            }
            else if(right == -1){
                mem[y][x] = grid[y][x] + down;
                return grid[y][x] + down;
            }
            else if(down == -1){
                mem[y][x] = grid[y][x] + right;
                return grid[y][x] + right;
            }
            else if(right > down){
                mem[y][x] = grid[y][x] + down;
                return grid[y][x] + down;
            }
            else{
                mem[y][x] = grid[y][x] + right;
                return grid[y][x] + right;
            }
        }

        else{
            return -1;
        }
    }
};

int main(){
    Solution obj;

    vector<vector<int>> grid = {
        {9,9,0,8,9,0,5,7,2,2,7,0,8,0,2,4,8},
        {4,4,2,7,6,0,9,7,3,2,5,4,6,5,4,8,7},
        {4,9,7,0,7,9,2,4,0,2,4,4,6,2,8,0,7},
        {7,7,9,6,6,4,8,4,8,7,9,4,7,6,9,6,5},
        {1,3,7,5,7,9,7,3,3,3,8,3,6,5,0,3,6},
        {7,1,0,7,5,0,6,6,5,3,2,6,0,0,9,5,7},
        {6,5,6,3,8,1,8,6,4,4,3,4,9,9,3,3,1},
        {1,0,2,9,7,9,3,1,7,5,1,8,2,8,4,7,6},
        {9,6,7,7,4,1,4,0,6,5,1,9,0,3,2,1,7},
        {2,0,8,7,1,7,4,3,5,6,1,9,4,0,0,2,7},
        {9,8,1,3,8,7,1,2,8,3,7,3,4,6,7,6,6},
        {4,8,3,8,1,0,4,4,1,0,4,1,4,4,0,3,5},
        {6,3,4,7,5,4,2,2,7,9,8,4,5,6,0,3,9},
        {0,4,9,7,1,0,7,7,3,2,1,4,7,6,0,0,0},
    }; 

    std::cout << obj.minPathSum(grid) << endl;
}