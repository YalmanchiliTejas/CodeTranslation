#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Rect{
  int top,left,right,bottom;
  bool isInside(int x, int y){
    return (left <= x && x <= right && top <= y && y <= bottom);
  }
};
struct Page{
  string name;
  vector<Rect> button;
  vector<string> linkto;
};
struct Browser{
  int now;
  Browser():now(0){};
  void Click(int x, int y){ 
    for(int i = 0; i < hist[now].button.size(); ++i){
      if( hist[now].button[i].isInside( x, y ) ){
	GoNext( page_map[ hist[now].linkto[i] ] );
	return ;
      } 
    }
  }
  void Forward(){
    now++;
    if( now >= hist.size() )
      now--;
  }
  void Back(){
    now--;
    if( now < 0 )
      now = 0;
  }
  void Show(){
    cout << hist[now].name << endl;
  }
  void GoNext( Page p ){
    for(int i = now + 1; i < hist.size(); ++i){
      hist.erase( hist.begin() + now + 1 );
      --i;
    }
    ++now;
    hist.push_back( p );
  }
  vector<Page> hist;
  map<string, Page> page_map;
};

int main(){
  while(true){
    int pages;
    cin>>pages;
    Browser bw;
    if(pages==0)
      break;
    int W,H;
    cin >> W >> H;
    for(int i = 0; i < pages; ++i){
      Page tmp;
      int bi;
      cin >> tmp.name >> bi;
      for(int j = 0; j < bi; ++j){
	Rect button;
	string linkto;
	cin>>button.left>>button.top>>button.right>>button.bottom;
	cin>>linkto;
	tmp.button.push_back( button );
	tmp.linkto.push_back( linkto );
      }
      if(i == 0)
	bw.hist.push_back( tmp );
      bw.page_map[ tmp.name ] = tmp;
    }
    int insts;
    cin >> insts;
    for(int i = 0; i < insts; ++i){
      string inst;
      cin >> inst;
      if( inst == "click" ){
	int x, y;
	cin >> x >> y;
	bw.Click( x, y );
      }
      if( inst == "show" )
	bw.Show();
      if( inst == "forward" )
	bw.Forward();
      if( inst == "back" )
	bw.Back();
    }
  }
  return 0;
}