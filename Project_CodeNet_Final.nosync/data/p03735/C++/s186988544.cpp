#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;

int n;
ll Ans=1e18;
std::multiset<pii> s;
std::multiset<int> sr,sb;

inline void Update(){Ans=std::min(Ans,(*sr.rbegin()-*sr.begin())*ll(*sb.rbegin()-*sb.begin()));}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        pii x;
        scanf("%d%d",&x.first,&x.second);
        if(x.first>x.second)std::swap(x.first,x.second);
        s.insert(x),sr.insert(x.first),sb.insert(x.second);
    }
    Update();
    for(auto r:s)
    {
        int x=r.first,y=r.second;
        sr.erase(sr.find(x)),sr.insert(y);
        sb.erase(sb.find(y)),sb.insert(x);
        Update();
    }
    printf("%lld\n",Ans);
    return 0;
}