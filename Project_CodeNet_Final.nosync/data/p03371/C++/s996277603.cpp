#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y; //A,B,C = A,B,ABの値段 X,Y = A,Bの枚数
    cin>>A>>B>>C>>X>>Y;
    int AB = 2*C; //ABを奇数枚用意しても無駄なので偶数枚用意
    vector<int> V;
    for(int i = 0;i <= 100000;i++){
       V.push_back(i*AB+max(0,X-i)*A+max(0,Y-i)*B);
    }
    cout<<*min_element(V.begin(),V.end());
}