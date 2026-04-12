#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n;cin>>n;
    lint ans=0;
    vector<int> vec(n);for(int i=0;i<n;i++)cin>>vec[i];
    sort(all(vec));
    int reml=vec[0],remr=vec[0];
    int left=1,right=n-1;
    int nokori=n-1;
    bool L=false;
    while(nokori>0){
        if(nokori==1){
            if(L){
                ans+=max(abs(vec[left]-remr),abs(vec[left]-reml));
            }
            else{
                ans+=max(abs(vec[right]-remr),abs(vec[right]-reml));
            }
            nokori--;
        }
        else{
            if(L){
                ans+=abs(vec[left]-reml)+abs(vec[left+1]-remr);
                reml=vec[left];
                remr=vec[left+1];
                left+=2;
                L=false;
            }
            else{
                ans+=abs(vec[right]-reml)+abs(vec[right-1]-remr);
                reml=vec[right];
                remr=vec[right-1];
                right-=2;
                L=true;
            }
            nokori-=2;
        }
    }
    lint ans2=0;
    int reml2=vec[n-1],remr2=vec[n-1];
    int left2=0,right2=n-2;
    int nokori2=n-1;
    bool L2=true;
    while(nokori2>0){
        if(nokori2==1){
            if(L2){
                ans2+=max(abs(vec[left2]-remr2),abs(vec[left2]-reml2));
            }
            else{
                ans2+=max(abs(vec[right2]-remr2),abs(vec[right2]-reml2));
            }
            nokori2--;
        }
        else{
            if(L2){
                ans2+=abs(vec[left2]-reml2)+abs(vec[left2+1]-remr2);
                reml2=vec[left2];
                remr2=vec[left2+1];
                left2+=2;
                L2=false;
            }
            else{
                ans2+=abs(vec[right2]-reml2)+abs(vec[right2-1]-remr2);
                reml2=vec[right2];
                remr2=vec[right2-1];
                right2-=2;
                L2=true;
            }
            nokori2-=2;
        }
    }
    cout<<max(ans,ans2)<<endl;
}
