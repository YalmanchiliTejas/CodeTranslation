#include <iostream>
using namespace std;

int main(){
    int n,s,avg;
    while (cin>>n && n!=0){
        int sum=0,ma=0,mi=1000;
        for (int i=0;i<n;i++){
            cin>>s;
            sum+=s;
            ma=max(ma,s); //最大値の更新
            mi=min(mi,s); //最小値の更新
        }
        avg=(sum-ma-mi)/(n-2); //平均の計算
        cout<<avg<<endl;
    }
}
