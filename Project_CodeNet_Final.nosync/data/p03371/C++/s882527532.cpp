#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int a;
    int b;
    int c;
    int y;
    int x;
    cin>>a>>b>>c>>y>>x;
    if (c<a && c<b){
    int sm=min(y,x);
    long long SUM=sm*c*2;
    long long ddd;
    long long eee;
    eee=abs(y-x)*c*2;
    if (y>x) ddd=(y-x)*a;
    else ddd=(x-y)*b;
    SUM+=min(ddd,eee);
    cout<<SUM<<endl;
    }
    else if (c<a || c<b) {
                            int aaa=y*a+x*b;
                            int bbb=max(y,x);
                            bbb*=c*2;
                            int ccc=min(y,x)*c*2;
                            if (y>x) ccc+=(y-x)*a;
                            else ccc+=(x-y)*b;
                            int ddd=min(aaa,bbb);
                            int eee=min(ccc,ddd);
                            cout<<eee<<endl;
                         }
    else cout<<y*a+x*b<<endl;
    return 0;
}