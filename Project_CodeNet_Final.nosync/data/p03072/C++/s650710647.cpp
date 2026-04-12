#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
	int N;cin>>N;
	int *H = new int[N];
	for(int i=0;i<N;++i)cin>>H[i];
	int count=1;
	int max=H[0];
	for(int i=1;i<N;++i){
		if(max<=H[i]){
			count++;
			max=H[i];
			}
	}
	cout<<count<<endl;
    return 0;
}