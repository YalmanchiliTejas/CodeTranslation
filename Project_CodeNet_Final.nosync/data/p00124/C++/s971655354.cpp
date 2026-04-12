#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
#include<map>
#include<cstdio>
 
 
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1e13
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
 
typedef long long int ll;
#define MOD 1000000007

bool comp(const pair<string,int>& p,const pair<string,int>& q){
    return p.second > q.second;
  }

int main(){


    int n,a,b,c;
    char t;
    string s;
    cin >> n;

    while(n){
        vector<pair<string,int> > arr;
        REP(i,n){
            cin >> s >> a >> b >> c;
            arr.push_back(make_pair(s,3*a+c));
        }

        sort(arr.begin(),arr.end(),comp);
        REP(i,arr.size()){
            cout << arr[i].first << ',' << arr[i].second << endl;
        }
        cin >> n;
        if(n){
            cout << endl;
        }
    }

    return 0;
}

