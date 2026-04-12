#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
typedef long long Int;
template<class T> inline T sq(T x){return x*x;}
template<class T> inline void checkmin(T &a,T b){if(b<a)a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a)a=b;}

struct Rect {
  int x1, y1, x2, y2;
  string target;

  bool isin(int x, int y) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
  }
};

struct Page {
  string name;
  int B;
  vector<Rect> b;


  string click(int x, int y) {
    REP(i, B) {
      if( b[i].isin(x,y) )
        return b[i].target;
    }
    return "";
  }
};

int W, H;

int main() {
  for(int N; cin >> N, N; ) {
    cin >> W >> H;
    vector<Page> pages;
    REP(i, N) {
      Page page;
      cin >> page.name;
      cin >> page.B;
      REP(j, page.B) {
        Rect btn;
        cin >> btn.x1 >> btn.y1 >> btn.x2 >> btn.y2 >> btn.target;
        page.b.push_back( btn );
      }
      pages.push_back( page );
    }

    vector<int> buf;
    buf.push_back(0);
    int pos = 0;

    int M; cin >> M;
    REP(m, M) {
      string cmd;
      cin >> cmd;
      if( cmd == "click" ) {
        int x, y; cin >> x >> y;

        string next = pages[ buf[pos] ].click( x, y);
        if( next.size() > 0 ) {
          int idx = -1;
          REP(i, N) if( pages[i].name == next ) idx = i;
          buf.erase( buf.begin() + pos + 1, buf.end() );
          buf.push_back( idx );
          pos += 1;
        }
      }
      else if ( cmd == "show" ) {
        cout << pages[ buf[pos] ].name << endl;
      }
      else if( cmd == "back" ) {
        if( pos - 1 >= 0 ) pos--;
      }
      else if( cmd == "forward" ) {
        if( pos + 1 < buf.size() ) pos++;
      }
    }
    
  }
  return 0;
}