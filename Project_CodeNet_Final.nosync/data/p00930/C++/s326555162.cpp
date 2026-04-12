#include<bits/stdc++.h>
using namespace std;

#define INF (1<<29)

struct segtree{

  //テヲツ慊?・ツーツ湘・ツ?、テ」ツつ津ヲツアツづ」ツつ?」ツつ凝ァツ板ィ
  vector<int> datamin;
  //テゥツ??・ツサツカテァツ板ィ
  vector<int> delay;
  int n;

  //テ・ツ按敕ヲツ慊淌・ツ個?
  void init(int _n){
    n = 1;
    while( n < _n ) n*=2;
    datamin.resize( 2 * n );
    delay.resize( 2 * n );
  }

  //テァツーツ。テヲツ伉禿ァツ可暗ッツシツ暗ァツキツ湘・ツ陳古」ツ?ォテ・ツッツセテ」ツ?凖」ツつ凝・ツ?ヲテァツ青?ァツ?。テ」ツ?預nd0テ・ツ按敕ヲツ慊淌・ツ個姪ァツ?。テ」ツ?要er)
  void delaycalc(int k){
    datamin[k] = datamin[k]+delay[k];
    if( k+1 < n )
      for(int i=1;i<=2;i++)
        delay[2*k+i] = delay[2*k+i]+delay[k];
    delay[k] = 0;
  }
  

  //テ・ツ個コテゥツ鳴禿」ツ??a,b)テ」ツ??」ツ?ォテ、ツクツ?ヲツァツ佚」ツ?ォテ」ツ??テ」ツ??」ツつ津ィツカツウテ」ツ??
  void add(int a,int b,int x,int k,int l,int r){
    delaycalc(k);
    if( r<=a || b<=l ) return;
    else if( a<=l && r<=b ){
      delay[k] = x;
      delaycalc(k);
    } else {
      add( a, b, x, 2*k + 1, l, (l+r)/2 );
      add( a, b, x, 2*k + 2, (l+r)/2, r );
      datamin[k] = min( datamin[2*k+1], datamin[2*k+2] );
    }
  }

  //テ」ツ?づ」ツつ凝・ツ個コテゥツ鳴禿」ツ?ョテヲツ慊?・ツーツ湘・ツ?、テ」ツつ津ヲツアツづ」ツつ?」ツつ?
  int querymin(int a,int b,int k,int l,int r){
    delaycalc(k);
    if( r<=a || b<=l ) return INF;
    if( a<=l && r<=b ){
      return datamin[k]+delay[k];
    } else {
      int vl = querymin( a, b, 2*k+1, l,(l+r)/2 );
      int vr = querymin( a, b, 2*k+2, (l+r)/2,r );
      return min(vl,vr);
    }
  }


  void add( int a,int b,int x){ add( a, b, x, 0,0,n); }//テ・ツ環?」ツ?暗」ツつ?
  int querymin(int a,int b){ return querymin(a,b,0,0,n); }//テヲツ慊?・ツーツ湘・ツ?、テ・ツ渉姪・ツセツ?
};

int N,Q;
string str;
segtree S;
int main(){
  cin >> N >> Q;
  cin >> str;
  S.init(N);
  int cnt = 0;
  for(int i=0;i<N;i++){
    if( str[i] == '(' ) cnt++;
    else cnt--;
    S.add(i,i+1,cnt);
  }

  for(int i=0;i<Q;i++){
    int id; cin >> id; --id;
   
    if( str[id] == ')' ){
      str[id] = '(';
      S.add(id,id+N,2);

      int st = 0,ed = id;
      int res = id;
      while( st <= ed ){
        int h = (st + ed)/2;
        int mini = S.querymin(h,id+1);
        if( mini >= 2 ){
          ed = h-1; res = min( res, h );
        }
        else st = h+1;
      }
      str[res]  = ')';
      cout << res+1 << endl;
      S.add(res,id+N,-2);
    } else {// ( -> )
      str[id] = ')';
      S.add(id,id+N,-2);

      int st = 0,ed = id;
      int res = id;
      while( st <= ed ){
        int h = (st + ed)/2;
        int mini = S.querymin(h,h+1);       
        if( h+1 == mini) st = h + 1;
        else{
          ed = h-1; res = min( res, h );
        }
      }
      str[res]  = '(';
      cout << res+1 << endl;
      S.add(res,id+N,2);
      
    }    
  
  }

}