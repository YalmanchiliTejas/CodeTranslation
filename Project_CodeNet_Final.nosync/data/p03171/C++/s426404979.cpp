#include <iostream>

using namespace std;
long long a[100000],f[3000][3000];
int n;
long long qhd(int tt,int i,int j){
    if (i==j) {
        if (tt==1) return a[i];
        else return 0;
    }
    else{
    if (tt==1){
        if (f[i][j]==0){
            f[i][j]=max(qhd(tt^1,i+1,j)+a[i],qhd(tt^1,i,j-1)+a[j]);
        }
        return f[i][j];
    } else {
        if (f[i][j]==0){
            f[i][j]=min(qhd(tt^1,i+1,j),qhd(tt^1,i,j-1));
        }
        return f[i][j];
        }
    }
}
int main()
{
    long long sum=0,o;
    cin>>n;
    for (int i=0;i<n;++i){ cin>>a[i]; sum+=a[i];}
    o=qhd(1,0,n-1);
    cout<<2*o-sum;
}
