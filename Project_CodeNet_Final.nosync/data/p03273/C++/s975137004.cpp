#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long h,w;
    cin>>h>>w;
    char a[h][w];
    vector<long long> H(h,0),W(w,0);
    f(i,0,h){
        long long c=0;
        f(j,0,w){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                c++;
            }
        }
        if(c==w){
            H[i]=1;
        }
    }
    f(j,0,w){
        long long c=0;
        f(i,0,h){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                c++;
            }
        }
        if(c==h){
            W[j]=1;
        }
    }
    f(i,0,h){
        if(H[i]==0){
            f(j,0,w){
                if(W[j]==0){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
