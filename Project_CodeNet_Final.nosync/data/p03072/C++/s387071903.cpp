#include <iostream>
 
using namespace std;
 
int main(void)
{
    int N, H[21], i, j, count;
 
    cin >> N;
 
    count = N;
 
    for(i=1; i<=N; i++){
	cin >> H[i];
    }
 
    for(i=2; i<=N; i++){
	for(j=1; j<=i-1; j++){
	    if(H[j] > H[i]){
		count--;
		break;
	    }
	}
    }
 
    cout << count << endl;
 
    return 0;
}