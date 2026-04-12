#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int N;
long long X;
vector<long long> p, b;
long long ans;

void calc(int lv, long long life)
{
	if(life == 0)
		return;

	if(lv==0){
		life--;
		ans++;
		return;
	}

	long long half = (p[lv] + b[lv]) / 2;
	if(life >= half){
		life -= half;
		ans += p[lv]/2;

		if(life > 0){
			life--;
			ans++;

			calc(lv-1, life);
		}
		
	}
	else{
		life--;
		calc(lv-1, life);
	}
}

int main(void)
{
	cin >> N >> X;

	p = vector<long long>(N+1, 0);
	b = vector<long long>(N+1, 0);
	p[0] = 1;
	for(int i=0; i<N; i++){
		p[i+1] = 2*p[i] + 1;
		b[i+1] = 2*b[i] + 2;
	}

	//for(int i=0; i<N; i++)
	//	cout << i << " : " << p[i]+b[i] << endl;

	ans = 0;
	calc(N, X);

	cout << ans << endl;
	
	return 0;
}
