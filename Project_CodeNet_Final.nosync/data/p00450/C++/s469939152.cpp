#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<stack>
using namespace std;
struct data{
    int color,cnt;
    data(int a,int b){
        color=a;cnt=b;
    }
    data(){}
};
int main(){
    int n;
    while(cin>>n,n){
        int a;
        cin>>a;
        int lc=a,cnt=1;
        stack<data>S;
        for(int i=1;i<n;i++){
            cin>>a;
            if(lc==a){
                cnt++;
            }
            else{
                if(i&1){
                    if(!S.size()){
                        cnt++;
                    }
                    else{
                        data d=S.top();S.pop();
                        cnt+=d.cnt;
                        cnt++;
                    }
                }

                else{
                    S.push(data(lc,cnt));
                    cnt=1;
                }
                lc=a;
            }
            //cout<<i<<":"<<lc<<" "<<cnt<<endl;
        }
        S.push(data(lc,cnt));
        int sum=0;
        while(S.size()){
            data d=S.top();S.pop();
            //cout<<d.color<<" "<<d.cnt<<endl;
            if(d.color==0)sum+=d.cnt;
        }
        cout<<sum<<endl;
    }

}