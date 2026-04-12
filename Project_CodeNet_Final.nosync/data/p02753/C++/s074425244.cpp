#include <bits/stdc++.h>
using namespace std;
char p[4];
int main(){
 	for (int i=1;i<=3;i++){
    	p[i]=getchar();
    }
  	if (p[1]==p[2] && p[2]==p[3])cout << "No";
	else cout << "Yes";
	return 0;
}