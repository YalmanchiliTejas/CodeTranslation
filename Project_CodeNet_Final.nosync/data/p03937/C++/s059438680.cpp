#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include <iomanip>
#include<unordered_map>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=15;

string str[maxn];
bool f[maxn][maxn];
int h,w;

int main() {
    //freopen("in.cpp","r",stdin);
    cin>>h>>w;
    for(int i=0; i<h; i++)cin>>str[i];
    if(str[0][0]!='#') {
        cout<<"Impossible"<<endl;
    } else {
        f[0][0]=1;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(f[i][j]){
                int cnt=0;
                if(j+1<w&&str[i][j+1]=='#'){
                    f[i][j+1]=1;
                    cnt++;
                }
                if(i+1<h&&str[i+1][j]=='#'){
                    f[i+1][j]=1;
                    cnt++;
                }
                if(cnt==2){
                    f[i][j+1]=f[i+1][j]=0;
                }
            }
        }
        bool sign=0;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        if(str[i][j]=='#'&&!f[i][j])sign=1;
        if(sign)cout<<"Impossible"<<endl;
        else cout<<"Possible"<<endl;
    }
    return 0;
}
