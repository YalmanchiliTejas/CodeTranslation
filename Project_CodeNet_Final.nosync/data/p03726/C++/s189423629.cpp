//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include <fstream>
 

 
using namespace std ;

const int N = 1e5 + 5;
long long cnt[N];
long long odd[N];
bool win = false;
int n;
vector<int> graph[N];

void dfs(int v, int par = -1)
{
    odd[v] = 0;
    for (auto u: graph[v])
    {
        if (u != par)
        {
            dfs(u, v);
            cnt[v] += cnt[u];
            odd[v] += (cnt[u] % 2);
        }
    }
    cnt[v]++;
    //cout << v << " " << odd[v] << endl;
    if (odd[v] > 1)
    {
        win = true;
    }
}

 
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    if (n % 2)
    {
        cout << "First" << endl;
        exit(0);
    }
    dfs(0);
    if (win)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }

}




