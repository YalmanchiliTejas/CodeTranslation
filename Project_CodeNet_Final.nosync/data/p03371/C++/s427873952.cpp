#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b,c,x,y;
	int count[3];
	int dis;
	int total;
	cin >> a>>b>>c>>x>>y;
	
	count[0]=x;
	count[1]=y;
	count[2]=0;
	total=x*a+y*b;
	
	for(;;){
		// A,Bを1減らして、Cを2増やしたときのコスト減
		dis=-2*c;
		// cout << dis <<endl;
		if(count[0]>0)dis+=a;
		if(count[1]>0)dis+=b;
		if(dis>0){
			total-=dis;
			count[0]--;
			count[1]--;
			count[2]+=2;
		}else{
			break;
		}
	}
	cout << total <<endl;
	// cout << count[0]<<' '<<count[1]<<' '<<count[2]<<endl;
	return 0;
}