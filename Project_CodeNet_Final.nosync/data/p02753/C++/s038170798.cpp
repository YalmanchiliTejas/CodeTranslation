#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std; 

bool allCharactersSame(string s) 
{ 
    int n = s.length();
    for (int i = 1; i < n; i++) 
        if (s[i] != s[0]) 
            return false; 
  
    return true; 
}

int main() { 
	string s;
    cin >> s;
    if(allCharactersSame(s) == true){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
	
	return 0;		
    
}