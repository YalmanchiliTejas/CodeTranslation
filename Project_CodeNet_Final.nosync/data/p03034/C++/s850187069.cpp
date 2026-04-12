#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    int N;  cin >> N;
    vector<ll> s(N);
    for(int i=0; i<N; i++) cin >> s[i];

    ll ans = 0;
    for(int C=1; C<=N-2; C++){
        ll score = 0;
        int x = 0;
        set<int> st;
        while(N-1-x*C>0){
            int A = N - 1 - x*C;
            if(st.find(x*C) != st.end() || st.find(N-1-x*C) != st.end() || x*C == N-1-x*C || A < C){
                break;
            }
            score += s[x*C];
            score += s[N-1-x*C];
            st.insert(x*C);
            st.insert(N-1-x*C);
            ans = max(ans, score);
            x++;
        }
    }
    cout << ans << endl;
}
