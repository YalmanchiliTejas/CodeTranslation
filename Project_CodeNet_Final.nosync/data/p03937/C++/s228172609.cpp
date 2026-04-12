#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;
bool used[8][8];
   int n, m;
 
bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;	
}
int main(){
    cin >> n >> m;
    char a[8][8];
    for (int i = 0; i< n; i++)
    	for (int j = 0; j < m; j++){
    		cin >> a[i][j];
    	}
    int curx = 0;
    int cury = 0;
    if (a[0][0] == '#'){
    while (curx != n - 1 || cury != m - 1){
    	used[curx][cury] = 1;
    	int hod1 = 0, hod2 = 0;
    	if (check(curx + 1, cury) && a[curx + 1][cury] == '#'){
    		hod1 = 1;	
    	}
    	if (check(curx, cury + 1) && a[curx][cury + 1] == '#'){
    		hod2 = 1;
    	}
    	if (hod1 && hod2)
    	{
    		cout << "Impossible\n";
    		return 0;
    	}
    	if (!hod1 && !hod2){
    		cout << "Impossible\n";
    		return 0;
    	}
    	if (hod1){
    		curx = curx + 1;
    		used[curx][cury] = 1;
    	}else
    	{
    		cury = cury+1;
    		used[curx][cury] = 1;
    	}
    }
    }
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++){
    		if (a[i][j] == '#' && !used[i][j]){
    		cout << "Impossible\n";
    		return 0;
    	}
    	}
    cout << "Possible\n";
}