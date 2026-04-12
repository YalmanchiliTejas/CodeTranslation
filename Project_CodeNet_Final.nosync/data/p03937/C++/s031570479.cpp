#include<bits/stdc++.h>
using namespace std;

int main(){
  	int x,y,c;
	cin >> y >> x;
  	vector<string> a(y);
  	for(int i = 0; i<y;i++)	
    	cin >> a[i];
  	for(int i = 0; i < y; i++) {
      	for(int j = 0; j<x; j++) {
			if(a[i][j] =='#') {
              	c=0;
              	if(j!=x-1 && a[i][j+1] == '#')
                  	c++;
          		if(i!=y-1 && a[i+1][j] == '#')
                  	c++;
             	if(c!=1 && !(i==y-1 &&j==x-1)) {
                  	cout << "Impossible\n";
                	return 0; 
                }
            }
        }
    }
  	for(int i = 0; i < y; i++) {
      	for(int j =0; j<x; j++) {
          	if(a[i][j] =='#') {
              	c=0;
              	if(j != 0 && a[i][j-1] == '#')
                  	c++;
          		if(i!= 0 && a[i-1][j] == '#')
                  	c++;
             	if(c!=1 && !(i==0 && j==0)) {
                  	cout <<"Impossible\n";
                	return 0; 
                }
            }
        }
    }
  	cout << "Possible\n";
  	
}
