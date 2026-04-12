#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define It iterator
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;


int main() {
    //freopen("test.in","r",stdin);
    int x,y;
    cin>>x>>y;

    printf("%.6f",1./(1./x+1./y));

    return 0;
}
