#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	
	int angka1,angka2,angka3;
	scanf ("%d %d %d",&angka1,&angka2,&angka3);
	int hasil = (angka1*100) + (angka2*10) + angka3;
	if (hasil%4==0){
		printf ("YES\n");
	}
	else{
		printf ("NO\n");
	}
}
