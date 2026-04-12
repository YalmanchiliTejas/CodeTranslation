#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int ary[100010];

int main(){
	int N,hog,res,cnt,fla,bak;
	stack<int> st;
	while(true){
		cin>>N;
		if(N==0) break;
		for(int i=1;i<=N;i++){
			cin>>ary[i];
		}
		if(ary[1]==1) fla=1;
		else fla=0;
		st.push(1);
		for(int i=2;i<=N;i++){
			hog=ary[i];
			if(i%2){
				if(fla==hog){
					st.top()++;
				}
				else{
					st.push(1);
					fla=1-fla;
				}
			}
			else{
				if(fla==hog){
					st.top()++;
				}
				else{
					bak=st.top();
					st.pop();
					if(!st.empty()) {bak+=st.top();st.pop();}
					bak++;
					st.push(bak);
					fla=1-fla;
				}
			}
		}
		cnt=0;
		while(!st.empty()){
			hog=st.top();
			st.pop();
			if(fla==0) cnt+=hog;
			fla=1-fla;
		}
		cout<<cnt<<endl;
	}
	return 0;
}