#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}

int main()
{
    string s;cin>>s;
    sort(s.begin(),s.end());
    cout<<(s[0]==s[2]?"No":"Yes")<<endl;
}
