#include <iostream>
#include <vector>
using namespace std;
int main(){
int n;
while(cin>>n, n!=0){
int k=0;
vector<vector<int> >v(n, vector<int>(n));
for(int i=-n/2; i<=n/2; i++)
for(int j=0; j<n; j++)
v[(j-i+n)%n][(j+i+n)%n]=++k;
for(int i=0; i<n-1; i++){
for(int j=i+1; j<n; j++){
swap(v[i][j], v[j][i]);
}
}
for(int i=0; i<n; i++){
for(int j=0; j<n; j++)printf("%4d", v[i][j]);
cout<<"\n";			
}
}
return 0;
}