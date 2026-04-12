#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int maxn = 50005;
int n;
vector<int> a;
int dp[maxn * 2][3];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    int l=a[(int)a.size() - 1]; 
    int r=l;             
    int i=0, j = (int)a.size() - 2;
    long long int sum=0;
    while(i < j){
        int li = abs(l - a[i]), ri = abs(r - a[i]);
        int lj = abs(l-a[j]),rj = abs(r - a[j]);
        if(li>ri || lj>rj){ 
            if(li > lj){
                sum += li;
                l = a[i ++];
            }
            else{
                sum += lj;
                l = a[j --];
            }
        }
        else{
            if(ri > rj){
                sum += ri;
                r = a[i ++];
            }
            else{
                sum += rj;
                r = a[j --];
            }
        }
    }
    sum += max(abs(l - a[i]),abs(r - a[i]));
    cout << sum << endl;
    return 0;
}