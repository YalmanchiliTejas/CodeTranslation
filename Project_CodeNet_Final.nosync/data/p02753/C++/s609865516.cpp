#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
//typedef vector<int> vi;
//using ll = long long; //only for C++11 compiler and newer
 
using namespace std;
template<typename T>
inline T Abs(T a){return a < 0 ? -a : a; }
template<typename T>
inline T Max(T a, T b){return a < b ? b : a; }
template<typename T>
inline T Min(T a, T b){return a > b ? b : a; }
 
int main(){
    //fast()
    //freopen("input.txt","r",stdin);
    string str; cin >> str;
    bool ans = false;
    for(int i = 0; i < 2; i++){
        if(str[i] != str[i + 1]){ans = true; break;}
    }
    if(ans) Yes();
    else No();
    return 0;
}