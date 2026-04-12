#include<bits/stdc++.h>
using namespace std;

int N;
char C[100010];

char change(char a,char b){
    if(a==b) return 'T';
    if(a=='F' || b=='T') return 'T';
    else return 'F';
}

int main() {
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> C[i];
    }
    char ans = change(C[1],C[2]);
    for(int i=3;i<=N;i++){
        ans = change(ans,C[i]);
    }
    cout << ans << endl;
}   

