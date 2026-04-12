#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
void solve(int n) {
	stack<int> stk;
	int head = -1;
	rep(i,n){
		int x=0;
		cin>>x;
		if(i%2==0){
			if(head==x){
				int tmp = stk.top();
				stk.pop();stk.push(tmp+1);
			}else{
				stk.push(1);
			}
			head=x;
		}else{
			if (head==-1) {
				head=x;stk.push(1);
			} else if(head==x) {
				int tmp = stk.top();
				stk.pop();stk.push(tmp+1);
			} else {
				//stk.size()!=0
				if (stk.size()==1){
					int tmp = stk.top();
					stk.pop();stk.push(tmp+1);
				} else {
					int tmp = stk.top();stk.pop();
					tmp += stk.top();stk.pop();
					stk.push(tmp+1);
				}
				head=x;
			}
		}
	}
	int ans=0;
	while(!stk.empty()){
		if(head==0){
			ans+=stk.top();
		}
		stk.pop();
		head=(head+1)%2;
	}
	cout<<ans<<endl;
}
int main () {
	int a;
	while(cin>>a&&a){
		solve(a);
	}
}