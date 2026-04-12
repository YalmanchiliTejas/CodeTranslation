#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
 
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
 
template <typename Type=int> class SegmentTree{
    public:
        int strnum;
        int strbeg;
        int nodemax;
        std::unique_ptr<Type[]> node;
        std::unique_ptr<std::pair<int,int>[]> noderange;
 
        SegmentTree(int a){
            strnum=a;
            strbeg=1;
            while(strbeg<strnum)strbeg*=2;
            strbeg-=1;
            nodemax=strbeg*2+1;
            node.reset(new Type[nodemax]);
            noderange.reset(new std::pair<int,int>[nodemax]);
            noderange[0]=std::make_pair(0,nodemax-strbeg-1);
            for(int i=1;i<nodemax;i++){
                int parent=(i-1)/2;
                int pleft=noderange[parent].first;
                int pright=noderange[parent].second;
                if(parent*2+1==i){
                    noderange[i]=std::make_pair(pleft,(pright+pleft)/2);
                }
                else{
                    noderange[i]=std::make_pair((pleft+pright)/2+1,pright);
                }
            }
        }
        Type operation(Type left,Type right){
            return max(left,right);
        }
        Type operation(Type left,Type center,Type right){
            return max(max(left,center),right);
        }
        void init(Type in){
            REP(i,nodemax)node[i]=in;
        }
        void update(int i,Type x){
            i+=strbeg;
            node[i]=x;
            while(i>0){
                i=(i-1)/2;
                node[i]=operation(node[2*i+1],node[2*i+2]);
            }
        }
        Type find(int l,int r,int n=0){
            std::pair<int,int> ran=noderange[n];
            int center=(ran.first+ran.second)/2;
            if(l==ran.first&&r==ran.second)return node[n];
            else if(center<l)return find(l,r,2*n+2);
            else if(center>=r)return find(l,r,2*n+1);
            else return operation(find(l,center,2*n+1),find(center+1,r,2*n+2));
        }
        Type f2(int l,int r,int num){
            if(r==l){
                if(find(l,l)>=num)return l;
                else return -1;
            }
            if(r-1==l){
                if(find(l,l)>=num) return l;
                else if(find(r,r)>=num) return r;
                else return -1;
            }
            int h=(l+r)/2;
            if(find(l,h)>=num)return f2(l,h,num);
            else return f2(h+1,r,num);
        }
};
 
int main(){
    int n;
    ll a[100005]={};
    scanf("%d",&n);
    int col=0;
    SegmentTree<ll> seg(100005);
    seg.init(-1);
    REP(i,n){
        scanf("%lld",&a[i]);
        seg.update(i,a[i]);
    }
    while(seg.find(0,n-1)>-1){
        int now;
        ll nownum;
        now=seg.f2(0,n-1,0);
        nownum=seg.node[now+seg.strbeg];
        //printf("%d %lld\n",now,nownum);
        seg.update(now,-1);
        while(now<n-1&&seg.find(now+1,n-1)>nownum){
            now=seg.f2(now+1,n-1,nownum+1);
            nownum=seg.node[now+seg.strbeg];
            //printf("%d %lld\n",now,nownum);
            seg.update(now,-1);
        }
        col++;
    }
    printf("%d\n",col);
    return 0;
}