#include <bits/stdc++.h>

using namespace std;

int dp0[110][5];
int dp1[110][5];

int main(){
    string s;
    int k, ans = 0;
    cin >>s>>k;

    int len =s.length();
    dp1[0][0] = 1;

    for(int i=0;i<len;i++){
        for(int c=0;c<=k;c++){
            dp0[i+1][c] += dp0[i][c];
            dp0[i+1][c+1] += dp0[i][c] * 9;

            for(int j=0;j<s[i]-'0';j++){
                if(j==0)
                    dp0[i+1][c] += dp1[i][c];
                else
                    dp0[i+1][c+1] += dp1[i][c];
            }

            if(s[i]-'0'){
                dp1[i+1][c+1] += dp1[i][c];
            }
            else{
                dp1[i+1][c] += dp1[i][c];
            }
        }
    }

    cout <<dp0[len][k] + dp1[len][k]<<endl;
}
