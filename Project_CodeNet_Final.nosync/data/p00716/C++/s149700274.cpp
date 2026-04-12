#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; ++i){
    int year,many,m,max;    
    cin >> many;
    cin >> year;
    cin >> m;
    //cout << "dbg3" << endl;
    double way[m][3];
    for(int j=0; j<m; ++j){
      cin >> way[j][0] >> way[j][1] >> way[j][2];
      //  cout << "dbg2" << endl;
    }
    //cout << "dbg1" << endl;
    max = 0;
    int tmp_m;
    
    for(int j=0; j<m; ++j){

      if(way[j][0] == 0){
	tmp_m = many;
	int risi = 0;
	for(int k=0; k<year; ++k){
	  risi  += tmp_m * way[j][1];
	  tmp_m -= way[j][2];
	} 
	tmp_m += risi;
      }else if(way[j][0] == 1){
	tmp_m = many;
	for(int k=0; k<year; ++k){
	  tmp_m  = tmp_m * (1 + way[j][1]);
	  tmp_m -= way[j][2];
	}
      }
      if(max<tmp_m){
      max = tmp_m;
      }
    }
    cout << max << endl;;
  }
  return 0;
}
    