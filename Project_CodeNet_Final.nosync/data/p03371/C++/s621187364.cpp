#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int money1(int x , int y){
    int ans;
    ans=x*y*2;
    return ans;
}

int money2(int a , int b , int c , int d){
    int x,y,ans;
    x=a-b;
    ans=b*d*2+x*c;
    return ans;
}

int main()
{
    int A,B,C,X,Y,ans;
    cin>>A>>B>>C>>X>>Y;
    if(A+B<=C*2){
        ans=A*X+B*Y;
    }else{
        if(X>=Y){
            if(A>2*C){
                ans=money1(X,C);
            }else{
                ans=money2(X,Y,A,C);
            }
        }else{
            if(B>2*C){
                ans=money1(Y,C);
            }else{
                ans=money2(Y,X,B,C);
            }
        }
    }
    cout<<ans<<endl;
}