#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e9
#define eps 1e-6
#define PI acos(-1.0)
#define M 10010
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;

int h,w;
int a[110][110];

int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin >> h >> w;
  for(int i = 0 ; i < h ; i++)
  {
     for(int j = 0 ;  j < w; j++)
     {
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 1;
        else a[i][j] = 0;
     }
  }
  for(int i = 0 ; i < h ; ++i)
  {
     int flag = 1;
     for(int j = 0 ; j < w; j++)
     {
        if(!a[i][j]) 
        {
           flag = 0;
           break;
        }
     }
     if(flag)
     {
         for(int j = 0 ; j < w; j++)
           a[i][j] = -1;
     }


  }
  for(int i = 0 ; i < w ; ++i)
  {
     int flag = 1;
     for(int j = 0 ; j < h; j++)
     {
        if(!a[j][i]) 
        {
           flag = 0;
           break;
        }
     }
     if(flag)
     {
         for(int j = 0 ; j < h; j++)
           a[j][i] = -1;
     }
  }
  
  for(int i = 0 ; i < h;  ++i)
  {
    int flag = 0;
    for(int j = 0 ; j < w; j++)
    {
       if(a[i][j] == 1) 
        {
          cout << '.';
          flag = 1;
        }
       if(a[i][j] == 0) 
        {
          cout << '#';
          flag = 1;
        }
    }
    if(flag)cout << endl;
  }

  //system("pause");
  return 0;
}