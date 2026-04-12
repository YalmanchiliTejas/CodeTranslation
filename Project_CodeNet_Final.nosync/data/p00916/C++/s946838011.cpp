#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

struct Point {
  int x,y;
};

struct Segment {
  Point p1,p2;
};

int n;
int d[] = {1,0,-1};
vector<Segment> segs;
const int M = 500;
bool field[M][M],visited[M][M];

vector<int> compress(int type){
  vector<int> vec,buf;
  rep(i,(int)segs.size()) {
    if( type ) {
      vec.push_back(segs[i].p1.y*2);
      vec.push_back(segs[i].p2.y*2);
      vec.push_back(segs[i].p1.y+segs[i].p2.y);
    }
    else {
      vec.push_back(segs[i].p1.x*2);
      vec.push_back(segs[i].p2.x*2);
      vec.push_back(segs[i].p1.x+segs[i].p2.x);
    }
  }
  rep(i,(int)vec.size()) {
    rep(j,3) {
      int cp = vec[i] + d[j];
      buf.push_back(cp);
    }
  }
  vec = buf;
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()),vec.end());
  return vec;
}

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void compute() {
  memset(field,false,sizeof(field));
  vector<int> xs = compress(0);  
  vector<int> ys = compress(1);

  //rep(i,(int)xs.size()) cout << xs[i] << " "; puts("");
  //rep(i,(int)ys.size()) cout << ys[i] << " "; puts("");

  rep(i,(int)segs.size()) {
    int p1,p2,base;
    if( segs[i].p1.x == segs[i].p2.x ) { // y
      p1 = lower_bound(ys.begin(),ys.end(),segs[i].p1.y*2) - ys.begin();
      p2 = lower_bound(ys.begin(),ys.end(),segs[i].p2.y*2) - ys.begin();
      base = lower_bound(xs.begin(),xs.end(),segs[i].p1.x*2) - xs.begin();
      if( p1 > p2 ) swap(p1,p2);
      //cout << "Y " << base << " : " << p1 << " => " << p2 << endl;
      REP(i,p1,p2+1) field[i][base] = true;
    } else { // x
      p1 = lower_bound(xs.begin(),xs.end(),segs[i].p1.x*2) - xs.begin();
      p2 = lower_bound(xs.begin(),xs.end(),segs[i].p2.x*2) - xs.begin();
      base = lower_bound(ys.begin(),ys.end(),segs[i].p1.y*2) - ys.begin();
      if( p1 > p2 ) swap(p1,p2);
      //cout << "X " << base << " : " << p1 << " => " << p2 << endl;
      REP(i,p1,p2+1) field[base][i] = true;
    }
  }

  /*
  rep(i,30) {
    rep(j,30) {
      cout << field[i][j];
    } puts("");
  }
  */
  rep(i,M) rep(j,M) visited[i][j] = field[i][j];
  int cnt = 0;
  rep(i,M) rep(j,M) if( !visited[i][j] ) {
    visited[i][j] = true;
    ++cnt;
    deque<int> deq;
    deq.push_back(j+i*M);
    while(!deq.empty()){
      int cur = deq.front(); deq.pop_front();
      rep(j,4){
	int nx = cur % M + dx[j], ny = cur / M + dy[j];
	if( !( 0 <= nx && nx < M && 0 <= ny && ny < M ) ) continue;
	if( visited[ny][nx] ) continue;
	visited[ny][nx] = true;
	deq.push_back(nx+ny*M);
      }
    }
  }
  cout << cnt << endl;
}

int main(){
  while( cin >> n, n ) {
    segs.clear();
    rep(_,n){
      int l,t,r,b;
      cin >> l >> t >> r >> b;
      segs.push_back((Segment){(Point){l,t},(Point){r,t}});
      segs.push_back((Segment){(Point){r,t},(Point){r,b}});
      segs.push_back((Segment){(Point){l,b},(Point){r,b}});
      segs.push_back((Segment){(Point){l,t},(Point){l,b}});
    }
    compute();
  }
  return 0;
}