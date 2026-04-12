#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

int N;
int takasa[30];
int now;
int kotae;


int main(){
  now = 0;
  kotae = 0;
	cin >> N;
	for(int i=0;i<N;i++){
    cin >> takasa[i];
	}

  for(int i=0;i<N;i++){
    if(now <= takasa[i]){
      kotae ++;
      now = takasa[i];
    }
  }
  cout << kotae << endl;
  return 0;
}