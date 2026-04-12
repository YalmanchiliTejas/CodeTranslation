#include<bits/stdc++.h>
#define rep(i,s,n) for(int i = s;i<n;i++)
#define long long ll
using namespace std;
struct Num{
    int no;
    int num;
};
int cmp(Num a,Num b){
    return a.num<b.num;
}
int main()
{

    int n;
    while(cin>>n){
        Num a[n];
        Num b[n];
        rep(i,0,n){
            int num;
            cin>>num;
            a[i].num = num;
            a[i].no = i;
        }
        sort(a,a+n,cmp);
        rep(i,0,n) {
            b[i].no  = i;
            b[i].num = a[i].no;
        }
        sort(b,b+n,cmp);
        rep(i,0,n){
            int t = (n)/2;
            int n = b[i].no;
            if(n<t){
                cout<<a[t].num<<endl;
            }else{
                cout<<a[t-1].num<<endl;
            }
        }
    }
}
