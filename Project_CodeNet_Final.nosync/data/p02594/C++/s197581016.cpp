#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main()
{
    // 文字列の入力
    int N;
	cin >> N;
	
	if(N >= 30) {
		printf("Yes\n");
	}else {
		printf("No\n");
	}
		
    return 0;
}