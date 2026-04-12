#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int maney,tf,minu;
int year;
int m,n;
double x;
int ans[101];


int main(){

  cin >> m;
  while(m){
    //テ・ツ青?」ツδ?」ツδシテ」ツつソテ」ツつサテ」ツδε」ツδ暗」ツ?ォテ・ツッツセテ」ツ?療」ツ?ヲテ」ツ??
    for(int i = 0; i < 101; i++){
      ans[i] = INF;
    }
    
    cin >> maney >> year >> n;

    for(int i = 0; i < n ; i++){
      //テ・ツ青?ゥツ?凝ァツ板ィテヲツ鳴ケテヲツウツ陛」ツ?ォテ・ツッツセテ」ツ?療」ツ?ヲテ」ツ??
      cin >> tf >> x >> minu;
      int mtmp = maney;
      if(tf){
	//ティツ、ツ?・ツ按ゥ

	for(int k = 0; k < year; k++){
	  int tmp = mtmp * x;
	  mtmp += (int)tmp;
	  mtmp -= minu;
	}
	ans[i] = mtmp;

      }else{
	//テ・ツ債佚・ツ按ゥ
	int r = 0;
	for(int k = 0; k < year; k++){
	  r += mtmp * x;
	  mtmp -= minu;
	}
	ans[i] = mtmp + r;
      }

    }
    sort(ans, ans+n);
  
    cout << ans[n-1] << endl;    
    m--;
  }

  return 0;

}