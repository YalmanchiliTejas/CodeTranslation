#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <sys/timeb.h>
#include <cstdio>
#include <sys/time.h>

using namespace std;
#define ll long long
#define uint unsigned int
#define ulong unsigned long long int

template<typename T> bool InRange(T t, T l, T r){ return l <= t && t < r; }

int main(){
	
	int H,W;
	cin >> H >> W;
	vector<string> S(H);
	for(int i=0;i<H;i++) cin >> S[i];
	
	int remC[W];
	int remR[H];
	for(int i=0;i<H;i++) remR[i] = 0;
	for(int j=0;j<W;j++) remC[j] = 0;
	
	for(int i=0;i<H;i++){
		bool chk = true;
		for(int j=0;j<W;j++) chk &= S[i][j] == '.';
		if(chk)  remR[i] = 1;
	}
	for(int j=0;j<W;j++){
		bool chk = true;
		for(int i=0;i<H;i++) chk &= S[i][j] == '.';
		if(chk) remC[j] = 1;
	}
	
	for(int i=0;i<H;i++){
		if(remR[i] == 1) continue;
		for(int j=0;j<W;j++) if(remC[j] == 0) cout << S[i][j];
		cout << endl;
	}
	
	
	
    return 0;
}