#include <iostream>
#define ft(i,a,b) for(int i=a; i<=b; ++i)

using namespace std;

long f[10005][100][3], d;
const int MOD = 1000000007;
string k;

long calc(const string &s) {
    int len=s.size();
    ft(x,1,9) {
        int st=((x==s[0]-'0')? 1 : ((x>s[0]-'0')? 2 : 0));
        f[1][x%d][st]++;
    }
    for(int i=1; i<=len; ++i) {
        for(int r=0; r<d; ++r) {
            for(int st=0; st<=2; ++st) {
                if (f[i][r][st]==0) continue;
                    for(int x=0; x<=9; ++x) {
                        int newr=(r+x)%d;
                        int newst=st;
                        if (st==1)
                        {
                            if (x>s[i]-'0') newst=2;
                            if (x==s[i]-'0') newst=1;
                            if (x<s[i]-'0') newst=0;
                        }
                        (f[i+1][newr][newst]+=f[i][r][st]) %= MOD;
                    }
            }
        }
    }

    long long ans=0;
    for(int i=1; i<=len; ++i) {
        for(int st=0; st<=((i==len)? 1 : 2) ; ++st) {
            (ans+=f[i][0][st] % MOD) %= MOD;
        }
    }
    return ans%MOD;
}

int main() {
//    freopen("INPUT.TXT","r",stdin);
//    freopen("OUTPUT.TXT","w",stdout);
    cin>>k>>d;
    cout<<calc(k);
    return 0;
}
