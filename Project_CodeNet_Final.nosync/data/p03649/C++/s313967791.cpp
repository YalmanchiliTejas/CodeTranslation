#include <bits/stdc++.h>


using namespace std;

long long lmax( long long a[]){
    long long m = 0;
    for (int i=0;i<55;++i)
    {
        m = a[i]>m?a[i]:m;
    }
    return m;
}
int main(){


    int n;
    long long a[55]={};
    cin >> n;
    for(int i=0;i<n;++i)cin >> a[i];
    long long c = 0;
    long long cnt = 0;
    while(lmax(a)>n-1){
        long long k = lmax(a);
        c = k/n;
        cnt += c;
        int f=1;
        for(int i=0;i<n;++i){
            if(f==1 && a[i]==k){
                f=0;
                a[i]-=c*n;
            }else{
                a[i]+=c;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}