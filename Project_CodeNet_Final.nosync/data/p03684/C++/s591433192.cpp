#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;
int par[100010];
int rank1[100010];

void init(int n)
{
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank1[i] = 0;
    }
}

int find(int x)
{
    if(par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y){
        return ;
    }
    if(rank1[x] , rank1[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(rank1[x] == rank1[y]){
            rank1[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

bool comp(pair<int, pair<int, int> > in1, pair<int, pair<int, int> > in2)
{
    return in1.first > in2.first;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    init(n);
    vector<pair<int, int> > y(n);
    vector<pair<int, int> > x(n);
    for(int i = 1; i <= n; i++){
        cin >> x[i - 1].first;
        cin >> y[i - 1].first;
        x[i - 1].second = i;
        y[i - 1].second = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<pair<int, pair<int, int> > > distance;
    for(int i = 0; i < n - 1; i++){
        pair<int, pair<int, int> > in;
        in.second.first = x[i].second;
        in.second.second = x[i + 1].second;
        in.first = x[i + 1].first - x[i].first;
        distance.push_back(in);
        in.second.first = y[i].second;
        in.second.second = y[i + 1].second;
        in.first = y[i + 1].first - y[i].first;
        distance.push_back(in);
    }
    long long ans = 0;
    sort(distance.begin(), distance.end(), comp);
    for(int i = 1; i < n; i++){
        while(same(distance.back().second.first, distance.back().second.second)){
            distance.pop_back();
        }
        ans += (long long)distance.back().first;
        unite(distance.back().second.first, distance.back().second.second);
        distance.pop_back();
    }
    cout << ans << endl;
    return 0;
}