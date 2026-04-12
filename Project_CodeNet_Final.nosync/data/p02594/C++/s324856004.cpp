#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<class T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<class T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
template<class RandomAccessIterator>inline void psortb(RandomAccessIterator first,RandomAccessIterator last){using P=pair<decltype(first->first),decltype(first->second)>;sort(first,last,[](const P&p1,const P&p2){return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);});}

int main()
{
    cout<<(in()>=30?"Yes":"No")<<endl;
}
