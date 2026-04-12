#include<bits/stdc++.h>
using namespace std;
int main()
{
    int H, W; cin >> H >> W;
    vector<vector<char>> a(H,vector<char> (W));
    vector<int> cnth(H,-1);
    vector<int> cntw(W,-1);
    for(int i = 0; i < H; i++)
    {
      	for(int j = 0; j < W; j++)
        {
          	cin >> a.at(i).at(j);
        }
    }
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(a.at(i).at(j) == '#')
            {
                cnth.at(i) = i;
                break;
            }
    }   }
    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < H; j++)
        {
            if(a.at(j).at(i) == '#')
            {
                cntw.at(i) = i;
                break;
            }
        }
    }
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(cnth.at(i) != -1 && cntw.at(j) != -1)
            {
            	cout << a.at(cnth.at(i)).at(cntw.at(j));
            }
        }
        for(int j = 0; j < W; j++)
        {
          	if(cnth.at(i) != -1 && cntw.at(j) != -1)
            {
                cout << endl;
                break;
            }
        }
    }
}