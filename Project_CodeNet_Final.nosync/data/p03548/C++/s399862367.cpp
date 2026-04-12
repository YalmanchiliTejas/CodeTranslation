#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define rep(i, e) for (int i = 0; i < e; i++)
#define repp(i, s, e) for (int i = s; i < e; i++)
#define N_Max 100
#define Card_Max 36
#define ll long long

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main()
{
    int x,y,z,ans=0; cin>>x>>y>>z;
    ans = x/(y+z);
    if(x%(y+z)!=z)ans--;
    cout << ans << endl;
}