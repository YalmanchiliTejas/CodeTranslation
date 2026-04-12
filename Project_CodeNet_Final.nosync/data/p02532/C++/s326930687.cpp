#include <iostream>
#include <string>
using namespace std;

int main(){
	int n; cin >> n ; char mount[100][1000];
	string str; char ch;int num;int* i=new int[n];
	for(int j=0;j<n;j++) i[j]=0;
	while(1){
	cin >> str ;
	if(str=="quit") break;
	if(str=="push") {cin >> num ; cin >> ch ; mount[num-1][i[num-1]++]=ch;};
	if(str=="pop") {cin >> num ; cout << mount[num-1][--i[num-1]] << '\n' ;};
	if(str=="move") {int j,k; cin >> j >> k ; ch=mount[j-1][--i[j-1]];
	mount[k-1][i[k-1]++]=ch;};
	};
}