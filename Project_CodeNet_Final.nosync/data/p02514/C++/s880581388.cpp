#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;
const int MAX_NUM=10001;
const int MAX_V = 201;
const int INF=100000000;

class Situation{
public:
	int cost;
    int x,y;
    int num;
	Situation(int cost_,int x_,int y_,int num_){
		cost=cost_;
        x=x_;
        y=y_;
        num=num_;
	}
	Situation();
	bool operator<(const Situation &s)const{
		return s.cost < this->cost;
	}
};

vector<string> split(string v,char del){
	vector<string> strs;
	int head=0;
	for(int j = 0; j < v.size(); j++){
		if(v[j]==del){
			strs.push_back(v.substr(head,j-head));
			head=j+1;
		}
		else if(j==v.size()-1){
			strs.push_back(v.substr(head,j-head+1));
		}
	}
	return strs;
}

pair<int,int> s,g;
int maxNum=0;
int minNum=INF;
int d[MAX_V][MAX_V];
vector<pair<int,int> > points[MAX_NUM];
int w,h;
int field[MAX_V][MAX_V];

void dijkstra(int sx,int sy){
	priority_queue<Situation> que;
    for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_V; j++)
            d[i][j]=INF;
    d[sy][sx] = 0;
	que.push(Situation(0,sx,sy,0));
	while(!que.empty()){
        Situation p = que.top();
        que.pop();
        int cy=p.y;
        int cx=p.x;
        int cnum=field[cy][cx];
        if(d[cy][cx]<p.cost)
			continue;
        if(cnum==maxNum){
            // ツゴツーツδ仰づ鳴古シツつゥツつ、
            pair<int,int> np=g;
            int dit=abs(np.first-cy)+abs(np.second-cx);
            if(d[np.first][np.second]>d[cy][cx]+dit)
                d[np.first][np.second]=d[cy][cx]+dit;
            continue;
        }
        cnum++;
        if(cnum==1){
            cnum=minNum;
        }
        for(int i = 0; i < points[cnum].size(); i++){
            pair<int,int> np=points[cnum][i];
            int dit=abs(np.first-cy)+abs(np.second-cx);
            if(d[np.first][np.second]>d[cy][cx]+dit){
                d[np.first][np.second]=d[cy][cx]+dit;
                que.push(Situation(d[np.first][np.second],np.second,np.first,cnum));
            }
        }
	}
}

void solve(){

    while(cin>>w>>h&&!(h==0&&w==0)){
        string ss;
        getline(cin,ss);
        maxNum=0;
        minNum=INF;
        for(int i = 0; i < MAX_NUM; i++)
            points[i].clear();
        for(int i = 0; i < h; i++){
            //getline(cin,ss);
            //vector<string> sp=split(ss,' ');
            for(int j = 0; j < w; j++){
                string sp;
                cin>>sp;
                if(sp=="S"){
                    field[i][j]=0;
                    points[0].push_back(make_pair(i,j));
                    s.first=i;
                    s.second=j;
                }
                else if(sp=="G"){
                    g.first=i;
                    g.second=j;
                }
                else if(sp==".")
                    continue;
                else{
                    int to=atoi(sp.c_str());
                    field[i][j]=to;
                    points[to].push_back(make_pair(i,j));
                    maxNum=max(maxNum,to);
                    minNum=min(minNum,to);
                }
            }
        }
        dijkstra(s.second,s.first);
        cout<<d[g.first][g.second]<<endl;
    }
}
int main(){

    solve();

    return 0;
}