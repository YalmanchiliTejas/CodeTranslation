#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[105][4][2];

int main(){
        string s;
        cin>>s;
        int K;
        cin>>K;
        int n=s.size();
        dp[0][0][0]=1;
        for(int i=0;i<n;i++){//iはn桁目
                for(int j=0;j<4;j++){//jは非０の数の個数
                        for(int k=0;k<2;k++){//kはそれまでの桁ですでに与えられた数以下であることが決まっている場合１、そうでない場合０

                                int nd=s[i]-'0';
                                for(int d=0;d<10;d++){
                                        int ni=i+1,nj=j,nk=k;
                                        if(d!=0)nj++;
                                        if(nj>K)continue;
                                        if(k==0){
                                                if(d>nd)continue;
                                                if(d<nd)nk=1;
                                        }
                                        dp[ni][nj][nk]+=dp[i][j][k];
                                }
                        }
                }

        }
        int ans=dp[n][K][0]+dp[n][K][1];
        cout<<ans<<endl;
        return 0;
}
