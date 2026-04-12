#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#define ll long long
#define INF 10000000000000000
#define MOD 998244353
using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n==0){break;}
        int s[n];
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        sort(s,s+n);
        int S=0;
        for(int i=1; i<n-1; i++){
            S+=s[i];
        }
        cout<<S/(n-2)<<endl;
    }
    return 0;
}

