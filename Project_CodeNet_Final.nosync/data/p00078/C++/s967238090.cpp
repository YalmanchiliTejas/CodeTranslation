#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(void){
    int n,c;
    while(cin>>n,n!=0){
        c=1;
        vector<vector<int> >d(n,vector<int>(n));
        for(int i=-n/2; i<=n/2; i++){
			for(int j=0; j<n; j++){
				d[(j-i+n)%n][(j+i+n)%n]=c;
                c++;
            }
        }
        
		for(int i=0; i<n-1; i++){
			for(int j=i; j<n-1; j++){
				swap(d[i][j+1], d[j+1][i]);
			}
		}
        
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)printf("%4d", d[i][j]);
            cout<<"\n";
		}
	}
	return 0;
}