#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

vector<vector<char>> A(10,vector<char>(10,'.'));


int main() {
    int H,W;
    cin>>H>>W;
    int count=0;
    for(int i=1;i<=H;i++) {
        for (int j = 1; j <= W; j++) {
            cin >> A[i][j];
            if(A[i][j]=='#')count++;
        }
    }
    if(count==H+W-1){
        cout<<"Possible";
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}