#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int mx = 200005;

pii I[mx];
int B[mx];
int n;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> I[i].first;
        I[i].second = i;
    }
    sort(I,I+n);
}

void pro(){
    for(int i = 0; i < n; i++){
        B[I[i].second] = (i <= (n-2)/2 ? I[n/2] : I[(n-2)/2]).first;
    }
}

void output(){
    for(int i = 0; i < n; i++){
        cout << B[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    input();
    pro();
    output();
}
