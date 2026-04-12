#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
bool check(pi a,pi b){
    return a.F*b.S-a.S*b.F>=0;
}
template <class _T> _T line(_T a,_T b){
    return {b.F-a.F,b.S-a.S};
}
template <class _T> double dis(_T a,_T b){
    a=line(a,b);
    return sqrt(a.F*a.F+a.S*a.S);
}
double min(double a,double b){return a>b?b:a;}
pair<double,double> from,to;
double ans(pi x,pi y){
    pair<double,double>a,b,l,r;
    a={x.F,x.S};
    b={y.F,y.S};
    while(dis(a,b)>0.0001){
        l={(a.F*2+b.F)/3,(a.S*2+b.S)/3};
        r={(a.F+b.F*2)/3,(a.S+b.S*2)/3};
        if(dis(from,l)+dis(l,to)>dis(from,r)+dis(r,to))a=l;
        else b=r;
    }
    return min(dis(from,a)+dis(a,to),dis(from,b)+dis(b,to));
}
int main(){
    int n,now=0,cnt=2;
    vector<pair<pi,int>>v,ch;
    pi temp;
    double l=0,r=0;
    bool f=false;
    scanf("%d%d",&temp.F,&temp.S);
    from=temp;
    v.PB({temp,-2});
    scanf("%d%d",&temp.F,&temp.S);
    v.PB({temp,-1});
    to=temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&temp.F,&temp.S);
        v.PB({temp,i});
    }
    sort(v.begin(),v.end());
    ch.PB(v[0]);
    ch.PB(v[1]);
    for(int i=2;i<v.size();i++){
        while(ch.size()>1){
            if(!check(line(ch[ch.size()-2].F,ch.back().F),line(ch.back().F,v[i].F)))ch.pop_back();
            else break;
        }
        ch.PB(v[i]);
    }
    for(int i=(int)v.size()-2;i>=0;i--){
        while(ch.size()>1){
            if(!check(line(ch[ch.size()-2].F,ch.back().F),line(ch.back().F,v[i].F)))ch.pop_back();
            else break;
        }
        ch.PB(v[i]);
    }
    for(int i=1;i<ch.size();i++){
        if(f)l+=dis(ch[i].F,ch[i-1].F);
        else r+=dis(ch[i].F,ch[i-1].F);
        if(ch[i].S==-2||ch[i].S==-1)f=!f;
    }
    l=min(l,r);
    if(l==dis(from,to)||f){
        ch.clear();
        while(cnt){
            while(v[now].S==-1||v[now].S==-2)now++;
            ch.PB(v[now]);
            cnt--;
            now++;
        }
        while(now<v.size()){
            while(v[now].S==-1||v[now].S==-2){
                now++;
                if(now>=v.size())break;
            }
            if(now>=v.size())break;
            while(ch.size()>1){
                if(!check(line(ch[ch.size()-2].F,ch.back().F),line(ch.back().F,v[now].F)))ch.pop_back();
                else break;
            }
            ch.PB(v[now]);
            now++;
        }
        now=(int)v.size()-2;
        while(now>=0){
            while(v[now].S==-1||v[now].S==-2){
                now--;
                if(now<0)break;
            }
            if(now<0)break;
            while(ch.size()>1){
                if(!check(line(ch[ch.size()-2].F,ch.back().F),line(ch.back().F,v[now].F)))ch.pop_back();
                else break;
            }
            ch.PB(v[now]);
            now--;
        }
        l=ans(ch.front().F,ch.back().F);
        for(int i=1;i<ch.size();i++)l=min(l,ans(ch[i].F,ch[i-1].F));
    }
    printf("%.20lf\n",l);
}
