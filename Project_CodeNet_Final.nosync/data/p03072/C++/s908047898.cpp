#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	int h[25];
	int n,cnt = 0;
	bool f = true;
	scanf("%d",&n);
	for(int i = 0;i <n ;i ++) scanf("%d",&h[i]);
	for(int i = 0;i < n;i ++){
		f = true;
		for(int j = 0;j < i; j ++){
			if(h[i]<h[j]) f = false;
		} 
		if(f) cnt ++;
	}
	printf("%d",cnt);	
	//fclose(stdin);
    return 0;
}
