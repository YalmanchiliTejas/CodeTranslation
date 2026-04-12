#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#include<time.h>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<limits>
using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;

int cntDigists(ll n){
    int digits = 1;
    while(n/10)
    {
        digits++;
        n = n/10;
    }
    return digits;
}

void p1(){
    int a,b,c;
    cin >> a >> b >>c;
    if(c-b == b-a) cout<<"YES"<<endl;
    else cout<<"NO";
}

void p2() {
    string O,E;
    cin >> O;
    cin >> E;
    string result;

    for(int i=0; i<O.size(); ++i){
        result += O[i];
        if(i < E.size())
        result += E[i];
    }

    cout << result << endl;

}

void p3(){
    int n;
    cin >> n;
    vector<string> vs(n);
    for(int i=0; i<n; ++i){
        cin >> vs[i];
    }

    vector<int> a(26,1000);
    for(auto s: vs){
        int index = 0;
        vector<int> b(26,0);
        for(auto c : s){
            b[c-'a'] +=1 ;
           // cout<< b[index] << ' ';
            ++index;
        }
        for(int i=0; i<26; ++i){
            if(b[i] < a[i]) a[i] = b[i];
        }
    }
    string res;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] && a[i] != 1000){
            for(int j=0; j<a[i]; ++j){
                res += (i+'a');
            }
        }
    }
    cout << res <<endl;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    p3();
    return 0;
}

