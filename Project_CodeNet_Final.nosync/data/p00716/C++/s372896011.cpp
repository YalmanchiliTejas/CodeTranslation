#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

int main(){

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
	int G,y,n;
	cin >> G >> y >> n;
	int risi;
	double intere;
	long tes,res=0;
	for(int j=0;j<n;j++){
	    long temp=G,ti = 0;
	    cin >> risi >> intere>> tes;
	    for(int k=0;k<y;k++){
		if(risi){
		    temp *= 1.0 + intere;
		    temp -= tes;
		}else{
		    ti += temp*intere;
		    temp -= tes;
		}
	    }
	    temp += ti;
	    res = max(res,temp);
	}
	cout << res << endl;
    }

    return 0;
}