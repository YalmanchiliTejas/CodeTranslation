#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int INF = 1 << 20;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
    while(true){
        int n; cin >> n;
        if(n == 0){
            break;
        }
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int sum = 0;
        for(int i = 1; i < n-1; i++){
            sum += a[i];
        }
        cout << sum / (n-2) << endl;
    }
}

