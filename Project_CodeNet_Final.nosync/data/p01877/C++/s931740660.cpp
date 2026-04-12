#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
#define st(x) (x).first
#define ed(x) (x).second
#define INF (5000000)
#define mp make_pair
struct INIT{INIT(){ios::sync_with_stdio(false);cin.tie(0);}}init;

struct seg_Tree{
	P interval;int child_max,child_min,add,val;
	int size(){ return(ed(interval) - st(interval) + 1); }
	void setval(int s, int t){st(interval) = s, ed(interval) = t;}
	int getmax(){return child_max+add+val;}
    int getmin(){return child_min+add+val;}
	seg_Tree(){add = 0, child_max = 0,child_min=0,val=0;setval(1, 0);}
};
vector<seg_Tree> depth(INF);
void make_tree(int k, int s, int t){
	if (s <= t){
		depth[k].setval(s, t);
		if (depth[k].size() > 1){
			int l = 2 * k + 1;int r = l + 1;
			make_tree(l, s, (s + t) / 2);
			make_tree(r, (s + t) / 2 + 1, t);
			depth[k].child_max=0;
            depth[k].child_min=0;
		}
		else depth[k].val=0;
	}
}
int getmax(int k,P len){
	int l = 2 * k + 1;int r = l + 1;
	if (depth[k].interval == len)return depth[k].getmax();
	else if (ed(len) <= ed(depth[l].interval))return depth[k].add+getmax(l,len);
	else if (st(len) >= st(depth[r].interval))return depth[k].add+getmax(r,len);
	else return depth[k].add+max(getmax(l, mp(st(len), ed(depth[l].interval))), getmax(r, mp(st(depth[r].interval), ed(len))));
}
int getmin(int k,P len){
	int l = 2 * k + 1;int r = l + 1;
	if (depth[k].interval == len)return depth[k].getmin();
	else if (ed(len) <= ed(depth[l].interval))return depth[k].add+getmin(l,len);
	else if (st(len) >= st(depth[r].interval))return depth[k].add+getmin(r,len);
	else return depth[k].add+min(getmin(l, mp(st(len), ed(depth[l].interval))), getmin(r, mp(st(depth[r].interval), ed(len))));
}
//????´?????????????,?????¨???2?????¨????????????
void setval(int k,int key,int val){
	int l = 2 * k + 1;int r = l + 1;
	if (depth[k].interval == mp(key,key))depth[k].val=val;
	else {
		if 	(key <= ed(depth[l].interval))setval(l, key, val);
		else setval(r, key, val);
		depth[k].child_max=max(depth[l].getmax(),depth[r].getmax());
        depth[k].child_min=min(depth[l].getmin(),depth[r].getmin());
	}
}

//??????????????????
void add(int k, P len, int val){
	int l = 2 * k + 1;int r = l + 1;
	if (depth[k].interval == len)depth[k].add += val;
	else {
		if (ed(len) <= ed(depth[l].interval))add(l, len, val);
		else if (st(len) >= st(depth[r].interval))add(r, len, val);
		else {
			add(l, mp(st(len), ed(depth[l].interval)), val);
			add(r, mp(st(depth[r].interval), ed(len)), val);
		}
		depth[k].child_max=max(depth[l].getmax(),depth[r].getmax());
        depth[k].child_min=min(depth[l].getmin(),depth[r].getmin());
	}
}

int main() {
    int N,Q;
    cin>>N;
    int HALF=N/2;
    make_tree(0,0,HALF);
    for(int i = 1; i <= N; i++){
        int k;cin>>k;
        if(i<=HALF){
            setval(0,i,+k);
        }
        else{
         add(0,mp(N-i+1,N-i+1),-k);
        }
    }
    cin>>Q;
    for(int i = 0; i < Q; i++){
        int l,r,x;cin>>l>>r>>x;
        if(r<=HALF){
            add(0,mp(l,r),+x);
        }
        else if(l>=HALF+1){
            add(0,mp(N-r+1,N-l+1),-x);
        }
        else{
            add(0,mp(l,HALF),+x);
            add(0,mp(N-r+1,HALF),-x);
        }
        if(abs(getmax(0,mp(1,HALF)))+abs(getmin(0,mp(1,HALF)))==0)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}