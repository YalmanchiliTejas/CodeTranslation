#include<iostream>
#include<string>
using namespace std;

int main(){
	/* 一番上の数をtop
	 * 一番手前の数をfront
	 * 右側の数をright
	 */
	int n;//何回操作するか
	int ans[200];//答えの格納
	int anscount=0;//答えの数
	while(true){
		int top=1;
		int front=2;
		int right=3;
		int temp;//一時記憶
		cin>>n;
		if(n==0)break;
		string s;//文字列
		int sum=1;//合計
		for(int i=0; i<n; i++){
			cin>>s;
			if(s=="North"){
				temp=top;
				top=front;
				front=7-temp;
			}else if(s=="East"){
				temp=right;
				right=top;
				top=7-temp;
			}else if(s=="South"){
				temp=front;
				front=top;
				top=7-temp;
			}else if(s=="West"){
				temp=top;
				top=right;
				right=7-temp;
			}else if(s=="Right"){
				temp=front;
				front=right;
				right=7-temp;
			}else if(s=="Left"){
				temp=right;
				right=front;
				front=7-temp;
			}
			sum+=top;
		}
		ans[anscount]=sum;
		anscount++;
	}

	for(int i=0; i<anscount; i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}