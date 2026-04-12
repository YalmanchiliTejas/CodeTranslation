#include<iostream>
using namespace std;

int dp0[110][4];
int dp1[110][4]; //確定小於N

int main(){

    string n;
    int k;

    cin >> n >> k;

    int l = n.size();
    dp0[0][0] = 1;

    for(int i=0;i<l;i++){
        for(int j=0;j<=k;j++){

            if(dp0[i][j]){
                for(int h=0;h<=n[i]-'0';h++){
                    if(h+'0' == n[i]){
                        if(n[i]=='0'){
                            dp0[i+1][j] = 1;
                        }
                        else{
                            if(j+1<=k)
                                dp0[i+1][j+1] = 1;
                        }
                    }
                    else{
                        if(h==0){
                            dp1[i+1][j] += 1;
                        }
                        else{
                            if(j+1<=k)
                                dp1[i+1][j+1] += 1;
                        }
                    }
                }
            }

            dp1[i+1][j] += dp1[i][j];
            if(j+1<=k)
                dp1[i+1][j+1] += 9*dp1[i][j];
        }
    }

    /*for(int i=0;i<=l;i++){
        for(int j=0;j<=k;j++){
            cout << dp0[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0;i<=l;i++){
        for(int j=0;j<=k;j++){
            cout << dp1[i][j] << " ";
        }
        cout << endl;
    }*/


    cout << dp0[l][k]+dp1[l][k] << endl;

    return 0;
}
