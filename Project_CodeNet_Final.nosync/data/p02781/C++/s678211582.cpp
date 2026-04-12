#include<bits/stdc++.h>
using namespace::std;
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}

int main(){
    string s;
    int k;
    cin>>s>>k;
    //dp[s.size()][2][k+1]の三次元配列を作る
    auto dp=make_vector<int>(-1,s.size(),2,k+1);
    //d:見た桁
    //b:今まで見た桁で超えてるかどうか
    //t:0以外を何個とったか
    function<int(int,bool,int)>f=[&](int d,bool b,int t)->int{
        //k個以上取ったら無条件で消す
        if(t>k)return 0;
        //すべての桁を見終わって条件を満たすなら1を返す
        if(d==(int)s.size()){
            return k==t;
        }
        //以前に呼んだのをもう一回呼ぶ際はメモっておいたやつを呼ぶ
        if(dp[d][b][t]!=-1)return dp[d][b][t];
        //取れる最大の桁をmxに入れる
        int mx=b?9:s[d]-'0';
        int ans=0;
        //取れる桁を回す
        for(int i=0;i<=mx;++i){
            ans+=f(d+1,b||(i!=mx),t+(i!=0));
        }
        return dp[d][b][t]=ans;
    };
    cout<<f(0,0,0)<<endl;
}