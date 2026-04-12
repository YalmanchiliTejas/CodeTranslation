#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>>bfr(H,vector<char>(W,' '));
  for(int i = 0;i < H;i++)
  {
  	for(int j = 0;j < W;j++)
  	{
  		cin >> bfr.at(i).at(j);
  	}
  }
//高さを削っていく
  vector<vector<char>>aft1(H,vector<char>(W,' '));
  int i1 = 0,i2 = 0;
  for(int i = 0;i < H;i++)
  {
  	int cnt1 = 0;
  	for(int j = 0;j < W;j++)
  	{
  		if(bfr.at(i).at(j) == '#')
  		{
  			cnt1++;
  		}
  	}
  	if(cnt1 > 0)
  	{
  		for(int j = 0;j < W;j++)
  		{
  			aft1.at(i1).at(j) = bfr.at(i).at(j);
  		}
  		i1++;
  	}
  }
  vector<vector<char>>aft2(H,vector<char>(W,' '));
  for(int i = 0;i < W;i++)
  {
  	int cnt2 = 0;
  	for(int j = 0;j < H;j++)
  	{
  		if(aft1.at(j).at(i) == '#')
  		{
  			cnt2++;
  		}
  	}
  	if(cnt2 > 0)
  	{
  		for(int j = 0;j < H;j++)
  		{
  			aft2.at(j).at(i2) = aft1.at(j).at(i);
  		}
  		i2++;
  	}
  }
  for(int i = 0;i < H;i++)
  {
  	for(int j = 0;j < W;j++)
  	{
  		if(aft2.at(i).at(j) == ' ')
  		{
  			cout << endl;
  			break;
  		}
  		else if(j == W - 1)
  		{
  			cout << aft2.at(i).at(j) << endl;
  		}
  		else 
  		{
  			cout << aft2.at(i).at(j);
  		}
  	}
  }
}
