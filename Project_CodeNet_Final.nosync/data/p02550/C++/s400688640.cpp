#include <bits/stdc++.h>
using namespace std;




int main() {
	int64_t n,x,m;
	int flag = 0;
	int j = 0;;
	cin >> n >> x >> m;
	vector<int64_t>amari(m+1,0);
	vector<int64_t>times(m,0);
	amari.at(0)=x;
	int64_t s = x;
	for(int i=1;i<m+1;i++){
		
		int64_t t;
		t = (s*s)%m;
		
		s = t;
		if(t == 0){
			flag = 1;
			j = i;
			break;
		}
		else if(t == 1){
			flag =2;
			j = i;
			break;
		}
		else{
			amari.at(i)=t;
		}
	}
	int64_t answer = 0;
	
	
	if(flag == 1){
		for(int i =0;i<j;i++){
			answer += amari.at(i);

		}
		cout << answer << endl;

	}
	else if(flag == 2){
		for(int i =0;i<j;i++){
			answer += amari.at(i);


		}
		cout << answer + n - j << endl;

	}
	
	else{
		for(int i=0;i<m;i++){
			int64_t c = amari.at(i);
			times.at(c)++;
		}
		
		int64_t d = 0;;
		for(int i = 0;i<m;i++){
			if(times.at(i)>=2){
				d = i;
				break;
			}
		}
		
		int64_t e,f,g,h,k;
		e = 0;
		f = 0;
		int count = 0;
		for(int64_t i=0;i<m;i++){
			if(amari.at(i)== d){
				count ++;
				if(count == 1){
					e = i;
				}
				else if(count == 2){
					f = i;
				}

			}

		}
		
		g = f - e; 
		h = (n-e)/g;
		k = (n-e)%g;
		
		for(int i=e;i<f;i++){
			answer += amari.at(i);
		}
		answer *= h;
		for(int i =0;i<e;i++){
			answer += amari.at(i);

		}
		for(int i =e;i<e+k;i++){
			answer += amari.at(i);

		}
		
		cout << answer << endl;
	}
}


