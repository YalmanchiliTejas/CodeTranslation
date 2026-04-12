#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define all(v) v.begin(),v.end()
#define ve vector
#define vi vector<int>
#define vi2 vector<vi>
#define vl vector<long long>
#define vl2 vector<vl>

template <class T> T maxAny(T a, T b){
    if(a > b) return a;
    else return b;
}

template <class T> T minAny(T a, T b){
    if(a > b) return b;
    else return a;
}

int main(){
    int x;
    cin >> x;
    if(x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}