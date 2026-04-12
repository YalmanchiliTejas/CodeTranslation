#include <iostream>
#include <set>
using namespace std;
int main(){
  string s;
  set<char> right;
  string rs ="yuiophjklnm";

  for( int i=0;i<(int)rs.length();i++ )
    right.insert( rs[i] );


  while( cin>>s && s!="#" ){
    bool isR = right.find( s[0] )!=right.end(), bu;
    int ans=0;

    for( int i=1;i<(int)s.length();i++ ){
      bu = right.find( s[i] )!=right.end();
      if( isR!=bu ){
	isR=bu; ans++;
      }
    }

    cout << ans << endl;
  }
  return 0;
}