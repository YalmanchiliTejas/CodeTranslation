#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
	int team[200][3] = {{0}};
	int a,b;
	int cnt = 0;
	for(int i= 1;scanf("%d,%d",&a,&b);i++){
	    if(a+b==0)break;
        team[i][0] = a,team[i][1] = b;
        cnt++;
	}
	for(int i = 1; i <= cnt; i++){
        for(int j = i; j <= cnt; j++){
            if(team[i][1] < team[j][1]){
                swap(team[i][0],team[j][0]);
                swap(team[i][1],team[j][1]);
            }
        }
	}
	team[1][2] = 1;
	int rank = 1;
	for(int i = 2; i <= cnt; i++){
        if(team[i-1][1] > team[i][1])rank++;
        team[i][2] = rank;
	}
	int n;
	while(cin >> n){
	    int ans = 0;
        for(int i = 1; i <= cnt; i++){
            if(team[i][0] == n){
                ans = team[i][2];
                break;
            }
        }
        cout << ans << endl;
	}
	return 0;
}