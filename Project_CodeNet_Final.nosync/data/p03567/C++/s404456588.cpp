#include <bits/stdc++.h>
using namespace std;

bool FIND(string S, string T){
	if(S.find(T) == string::npos){
		return false;
	} else {
		return true;
	}
}

int main(){
    char S[10];
    scanf("%s", S);
    printf(FIND(S, "AC") ? "Yes\n" : "No\n");
    return 0;
}