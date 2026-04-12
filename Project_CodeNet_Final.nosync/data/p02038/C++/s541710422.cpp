#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> P;
int N,i=2;

char M(char A,char B){
    if(A == 'T' && B == 'F') return 'F';
    return 'T';
}

int main(){
    cin >> N;
    P.resize(N);
    for(int i=0;i<N;i++) cin >> P[i];

    char ans = M(P[0],P[1]);
    for(int i=2;i<N;i++) ans = M(ans,P[i]);

    cout << ans << endl;
}
