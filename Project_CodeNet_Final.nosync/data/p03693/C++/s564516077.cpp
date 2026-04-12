#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
 
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

int main() {
	int r,g,b;
	cin >>r>>g>>b;
	if((10*g+b)%4==0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}