#include <bits/stdc++.h>

using namespace std;

int n,i,j,id[100005];
char s[100005];

int solve(){
	for(int ii = 0; ii < n; ii++){
		if(id[ii] == 0)
		printf("S");
		else
		printf("W");
	}
	printf("\n");
	return 0;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	
	//sheep = 0, wolf = 1
	
	if(s[0] == 'o'){
		//0 is sheep
		id[0] = 0;
		//n - 1 and 1 is sheep
		id[1] = 0;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 0 && ((s[n - 1] == 'o' &&  id[n - 2] == id[0]) || (s[n - 1] == 'x' && id[n - 2] != id[0])))
		return 0 * solve();
		
		//n - 1 and 1 is wolf
		id[1] = 1;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 1 && ((s[n - 1] == 'o' &&  id[n - 2] != id[0]) || (s[n - 1] == 'x' && id[n - 2] == id[0])))
		return 0 * solve();
		
		//0 is wolf
		id[0] = 1;
		//n - 1 is wolf and 1 is sheep
		id[1] = 0;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 1 && ((s[n - 1] == 'o' &&  id[n - 2] != id[0]) || (s[n - 1] == 'x' && id[n - 2] == id[0])))
		return 0 * solve();
		//n - 1 is sheep and 1 is wolf
		id[1] = 1;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 0 && ((s[n - 1] == 'o' &&  id[n - 2] == id[0]) || (s[n - 1] == 'x' && id[n - 2] != id[0])))
		return 0 * solve();
	}
	else{
		id[0] = 0;
		//n - 1 is wolf and 1 is sheep
		id[1] = 0;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 1 && ((s[n - 1] == 'o' &&  id[n - 2] != id[0]) || (s[n - 1] == 'x' && id[n - 2] == id[0])))
		return 0 * solve();
		//n - 1 is sheep and 1 is wolf
		id[1] = 1;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 0 && ((s[n - 1] == 'o' &&  id[n - 2] == id[0]) || (s[n - 1] == 'x' && id[n - 2] != id[0])))
		return 0 * solve();
		
		id[0] = 1;
		//n - 1 and 1 is sheep
		id[1] = 0;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 0 && ((s[n - 1] == 'o' &&  id[n - 2] == id[0]) || (s[n - 1] == 'x' && id[n - 2] != id[0])))
		return 0 * solve();
		
		//n - 1 and 1 is wolf
		id[1] = 1;
		for(i = 1; i < n - 1; i++){
			if((s[i] == 'o' && id[i] == 0) || (s[i] == 'x' && id[i] == 1))
			id[i + 1] = id[i - 1];
			else
			id[i + 1] = 1 - id[i - 1];
		}
		if(id[n - 1] == 1 && ((s[n - 1] == 'o' &&  id[n - 2] != id[0]) || (s[n - 1] == 'x' && id[n - 2] == id[0])))
		return 0 * solve();
	}
	
	printf("-1\n");
}
