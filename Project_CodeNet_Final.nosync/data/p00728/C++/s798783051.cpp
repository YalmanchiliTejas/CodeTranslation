#include<algorithm>
#include<iostream>

using namespace std;
int main(){
	int n, max;
	int *score;

	while(1){
		cin >> n;
		if(n==0){
			break;
		}else{
			max = 0;
			score = new int[n];
			for(int i=0; i<n; i++){
				cin >> score[i];
			}
			sort(score, score+n);
			for(int i=1; i<n-1; i++){
				max += score[i];
			}
			cout << max/(n-2) << endl;

			delete [] score;
		}
	}

	return 0;
}