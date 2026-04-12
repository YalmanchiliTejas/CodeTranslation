#include <iostream>
#include <climits>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long int i,j,ans=0;
 
int ascSort(const void* v1, const void* v2) {
    const int _v1 = *((const int*)v1);
    const int _v2 = *((const int*)v2);
 
    if ( _v1 < _v2 ) {
        return 1;
    } else if ( _v1 > _v2 ) {
        return -1;
    } else {
        return 0;
    }
}
int INF = 1<<29;
const int mod = 1000000007;

int main(){
	string c;
	cin>>c;
	if(c=="a" ||c=="i" ||c=="u" ||c=="e" ||c=="o"){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
	return 0;
}