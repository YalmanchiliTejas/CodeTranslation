#include <iostream>
using namespace std;

int main(){


  int n;

  while(cin >> n){
    if(n == 0) break;

    //テ・ツ?・テ・ツ環?
    int point[200];
    for(int i = 0; i < n ; i++){
      cin >> point[i];
      //      cout << point[i] << " ";
    } 

    //max
    int max = -1;
    for(int i = 0 ; i < n ; i++){
      if(point[i] > max)
	max = point[i];
    }
    for(int i = 0 ; i < n ; i++){
      if(point[i] == max){
	point[i] = -1;
	break;
      }
    }

    //min
    int min = 10000;
    for(int i = 0 ; i < n ; i++){
      if(point[i] < min && point[i] != -1 )
	min = point[i];
    }
    for(int i = 0 ; i < n ; i++){
      if(point[i] == min){
	point[i] = -1; 
	break;     
      }
    }

    int ans = 0;
    for(int i = 0; i < n ; i++){
      if(point[i] > -1)
	ans += point[i];
      //  cout << point[i] << " ";
    }
    ans = ans / (n-2);
    cout << ans << endl;

  }

  return 0;
}