#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int diff = (a+b) - c*2;
    int old = a*x+b*y;
    if(diff <= 0){
        cout<<old<<endl;
    }
    else{
        int New = old - diff*min(x,y);
        int Yokei = c*max(x,y)*2;
        if(New < Yokei) cout<<New<<endl;
        else cout<<Yokei<<endl;
    }
}



