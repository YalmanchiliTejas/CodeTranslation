#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int n, m, *a, t;
	
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		
		a = (int *)calloc(n+m+1, sizeof(int));
		for(int i = 0; i < n+m; i++){
			cin >> a[i];
		}
		sort(a, a+(n+m));
		
		t = a[0];
		for(int i = 1; i < n+m; i++){
			if(t < a[i]-a[i-1]){
				t = a[i]-a[i-1];
			}
		}
		cout << t << endl;
		
		free(a);
	}
	
	return 0;
}