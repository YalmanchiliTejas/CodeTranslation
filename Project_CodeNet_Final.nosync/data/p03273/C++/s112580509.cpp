#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    int H, W;
    cin >> H >> W;
    
    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<int>> is_show(H, vector<int>(W, 1));
    
    for(int i = 0; i < H;i++)
    {
        bool all_white = true;
        
        for(int j = 0;j < W;j++)
        {
            cin >> grid[i][j];
            
            if(grid[i][j] == '#')
            {
                all_white = false;
            }
        }
        
        if(all_white)
        {
            for(int j = 0;j < W;j++)
            {
                is_show[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < W;i++)
    {
        bool all_white = true;
        
        for(int j = 0;j < H;j++)
        {
            if(grid[j][i] == '#')
            {
                all_white = false;
            }
        }
        
        if(all_white)
        {
            for(int j = 0;j < H;j++)
            {
                is_show[j][i] = 0;
            }
        }
    }
    
    for(int i = 0;i < H;i++)
    {
        bool is_output = false;
        for(int j = 0;j < W;j++)
        {
            if(is_show[i][j] == 1)
            {
                cout << grid[i][j];
                is_output = true;
            }
        }
        
        if(is_output)
        {
            cout << endl;
        }
    }
}
