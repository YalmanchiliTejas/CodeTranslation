// 2011/10/11 Tazoe

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	while(true){
		int n;
		cin >> n;
		if(n==0)
			break;

		stack<int> go;

		int c;
		cin >> c;
		int p = c;
		int m = 1;

		for(int i=1; i<n; i++){
			cin >> c;

			if(i%2==0){
				if(c==p){
					m++;
				}
				else{
					go.push(m);
					m = 1;
					p = c;
				}
			}
			else{
				if(c==p){
					m++;
				}
				else{
					if(!go.empty()){
						m += go.top();
						go.pop();
					}
					m++;
					p = c;
				}
			}
		}

		int cnt = 0;
		if(c==0){
			cnt += m;
			go.pop();
		}

		while(!go.empty()){
			cnt += go.top();
			go.pop();
			if(go.empty())
				break;
			go.pop();
		}

		cout << cnt << endl;
	}

	return 0;
}