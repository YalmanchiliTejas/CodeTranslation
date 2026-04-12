#include <iostream>
using namespace std;

char c;

int main(){
    cin >> c;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
	
    return 0;
}
