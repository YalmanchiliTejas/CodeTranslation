#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 200000 + 5;

int main(){
	string n;
	cin >> n;
	int k;
	cin >> k;
	int len = n.length();
	int sum;
	int z,z1;
	if (k == 1)
    	sum = 9 * (len - 1) + n[0] - '0';
  	else if (k == 2){
	    z = -1;
	    for(int i = 1; i < len; i++){
	    	if(n[i] > '0'){
	    		z = i;
	        	break;
	    	}
	    }
		sum = 81 * (len-1) * (len-2) / 2;
		sum += 9 * (len-1) * (n[0]-'1');
		if(z > 0){
	    	sum += n[z]-'0';
			sum += 9 * (len-z-1);
		}
	}
	else{
	    z = z1 = -1;
		for(int i = 1; i < len; i++){
	    	if(n[i] > '0'){
	        	if (z < 0)
	        		z = i;
	        	else if(z1 < 0)
	          		z1 = i;
			}  
    	}
	    sum = 729 * (len-1) * (len-2) * (len-3) / 6;
	    sum += 81 * (len-1) * (len-2) / 2 * (n[0]-'1');
	    if(z > 0){
		    sum += (n[z]-'1') * 9 * (len-z-1);
		    sum += 81 * (len-z-1) * (len-z-2) / 2;
		    if(z1 > 0){
				sum += n[z1]-'0';
				sum += 9 * (len-z1-1);
		    }
	    }
	}
	cout << sum << endl;
	return 0;
}