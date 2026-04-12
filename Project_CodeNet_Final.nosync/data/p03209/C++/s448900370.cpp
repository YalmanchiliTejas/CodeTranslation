#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define int long long

int a[51];
int p[51];

int saiki(int lev,int h){
    if(lev==1){
        if(h==1){
            return 0;
        }else if(h<5){
            return h-1;
        }else{
            return 3;
        }
    }else{
        if(h==1){
            return 0;
        }
        if(h<=1+a[lev-1]){
            return saiki(lev-1,h-1);
        }
        if(h==a[lev-1]+2){
            
            return 1+p[lev-1];
        }
        if(h<=2+2*a[lev-1]){
            return 1+p[lev-1]+saiki(lev-1,h-a[lev-1]-2);
        }

        return p[lev];
    }

}

signed main(){
    int n,x;
    cin >> n >> x;
    a[0] =1;
    a[1] =5;
    p[0] =1;
    p[1] =3;
    for(int i=2;i<51;i++){
        a[i]= 2*a[i-1]+3;
        p[i]= 2*p[i-1]+1;
    }
    cout << saiki(n,x) << endl;
    return 0;
}