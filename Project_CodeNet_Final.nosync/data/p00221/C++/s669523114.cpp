#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
//#include<cctype>

using namespace std;

class Player{
public:
  int id;
};

int main()
{
  while(true){
    int m,n;
    cin >> m >> n;
    if( m == 0 && n == 0 ) break;
    vector< Player > p;
    for(int i = 0; i < m; ++i){
      Player tp;
      tp.id = i+1;
      p.push_back( tp );
    }

    int ans = 1;
    int nowplayer = 0;
    string s;
    getline(cin,s);
    for(int i = 0; i < n; ++i){
      //getline(cin,s);
      cin >> s;
      if(p.size()==1)continue;
      
      bool erased = false;
      if(ans % 15 == 0 ){
	if( s != "FizzBuzz" ){
	  erased = true;
	}
      }else if( ans % 3 == 0 ){
	if( s != "Fizz" ){
	  erased = true;
	}
      }else if( ans % 5 == 0 ){
	if( s != "Buzz" ){
	  erased = true;
	}
      }else{
	erased=true;
	//!isdigit(s[0]);
	//false;
	//bool lead = true;
	/*
	for(int j = 0; j < s.length(); ++j){
	  if( !isdigit(s[j]) ){
	    ng=true;
	    break;
	  }
	  if( lead && s[j] == '0' ){
	    //s.erase( s.begin() + j );
	    ng = true;
	    break;
	    //j = -1;
	  }else{
	    lead=false;
	  }
	}
	if(s.length()==0)ng=true;
	if( s.length() >= 7 ) ng = true;
	*/
	int d = atoi( s.c_str() );
	if( d == ans ){
	  erased = false;
	}
      }
      if( !erased ){
	++nowplayer;
      }else{
	p.erase( p.begin() + nowplayer );
      }
      nowplayer %= p.size();
      ++ans;
    }

    for(int i = 0; i < p.size(); ++i){
      if( i > 0 ) cout << ' ';
      cout << p[i].id;
    }
    cout << endl;
  }
  return 0;
}