#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
int m, init, a,b,sum=0, year, n, *result, *type, *fee, i, j, k, l, o, *out,p;
double *rate;
	cin >> m;
	out = new int[m];
	for(i=0;i<m;i++){
		cin >> init;
		cin >> year;
	cin >> n;
	type = new int[n];
	rate = new double[n];
	fee = new int[n];
	result = new int[n];
	for(j=0;j < n;j++){
		cin >> type[j] >> rate[j] >> fee[j];
		b=0;
		a = init;
		sum=0;
		if(type[j]==0){
			for(k=0; k <year ;k++){
				b = a * rate[j];
				sum = sum + b;
				a = a -fee[j];
			
			}
		
			result[j] = a +sum;
		
		}else{
			for(l=0;l<year;l++){
				b = a * rate[j];
				a = a + b - fee[j];
			}
			result[j] = a;
		}
	}
	
	for(o =0;o<n;o++){
		if(result[o] > out[i]){
		out[i] = result[o];
		}

	}


	}


	for(p=0;p < m;p++){
		cout << out[p]<<endl;
	}

	return 0;
}