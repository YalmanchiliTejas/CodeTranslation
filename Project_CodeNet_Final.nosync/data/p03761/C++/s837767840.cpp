#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include<map>
using namespace std;



int main() {
	int n;
	cin >> n;
	string s;
	
	int A=0;
	int B=0;
	int C=0;
	int D=0;
	int E=0;
	int F=0; 
	int G=0;
	int H=0;
	int I=0;
	int J=0;
	int K=0;
	int L=0;
	int M=0;
	int N=0;
	int O=0;
	int P=0;
	int Q=0;
	int R=0;
	int S=0;
	int T=0;
	int U=0;
	int V=0;
	int W=0;
	int X=0;
	int Y=0;
	int Z=0;



	cin >> s;
	for (int i=0; i < s.size(); i++) {
		if (s[i] == 'a')A++;
		if (s[i] == 'b')B++;
		if (s[i] == 'c')C++;
		if (s[i] == 'd')D++;
		if (s[i] == 'e')E++;
		if (s[i] == 'f')F++;
		if (s[i] == 'g')G++;
		if (s[i] == 'h')H++;
		if (s[i] == 'i')I++;
		if (s[i] == 'j')J++;
		if (s[i] == 'k')K++;
		if (s[i] == 'l')L++;
		if (s[i] == 'm')M++;
		if (s[i] == 'n')N++;
		if (s[i] == 'o')O++;
		if (s[i] == 'p')P++;
		if (s[i] == 'q')Q++;
		if (s[i] == 'r')R++;
		if (s[i] == 's')S++;
		if (s[i] == 't')T++;
		if (s[i] == 'u')U++;
		if (s[i] == 'v')V++;
		if (s[i] == 'w')W++;
		if (s[i] == 'x')X++;
		if (s[i] == 'y')Y++;
		if (s[i] == 'z')Z++;
		
	}

	for (int k = 0; k < n - 1; k++) {
		cin >> s;
		int AA=0;
		int BB=0;
		int CC=0;
		int DD=0;
		int EE=0;
		int FF=0;
		int GG=0;
		int HH=0;
		int II=0;
		int JJ=0;
		int KK=0;
		int LL=0;
		int MM=0;
		int NN=0;
		int OO=0;
		int PP=0;
		int QQ=0;
		int RR=0;
		int SS=0;
		int TT=0;
		int UU=0;
		int VV=0;
		int WW=0;
		int XX=0;
		int YY=0;
		int ZZ=0;
		for (int i=0; i < s.size(); i++) {
			if (s[i] == 'a')AA++;
			if (s[i] == 'b')BB++;
			if (s[i] == 'c')CC++;
			if (s[i] == 'd')DD++;
			if (s[i] == 'e')EE++;
			if (s[i] == 'f')FF++;
			if (s[i] == 'g')GG++;
			if (s[i] == 'h')HH++;
			if (s[i] == 'i')II++;
			if (s[i] == 'j')JJ++;
			if (s[i] == 'k')KK++;
			if (s[i] == 'l')LL++;
			if (s[i] == 'm')MM++;
			if (s[i] == 'n')NN++;
			if (s[i] == 'o')OO++;
			if (s[i] == 'p')PP++;
			if (s[i] == 'q')QQ++;
			if (s[i] == 'r')RR++;
			if (s[i] == 's')SS++;
			if (s[i] == 't')TT++;
			if (s[i] == 'u')UU++;
			if (s[i] == 'v')VV++;
			if (s[i] == 'w')WW++;
			if (s[i] == 'x')XX++;
			if (s[i] == 'y')YY++;
			if (s[i] == 'z')ZZ++;
             }

		 A=min(A,AA);
		 B = min(B, BB);
		 C = min(C, CC);
		 D = min(D, DD);
		 E = min(E, EE);
		 F = min(F, FF);
		 G = min(G, GG);
		 H = min(H, HH);
		 I = min(I, II);
		 J = min(J, JJ);
		 K = min(K, KK);
		 L = min(L, LL);
		 M = min(M, MM);
		 N = min(N,NN);
		 O = min(O, OO);
		 P = min(P, PP);
		 Q = min(Q, QQ);
		 R = min(R, RR);
		 S = min(S, SS);
		 T = min(T, TT);
		 U = min(U, UU);
		 V = min(V, VV);
		 W = min(W, WW);
		 X = min(X, XX);
		 Y = min(Y, YY);
		 Z = min(Z, ZZ);

	}
	int k = 0;
	string q[100];
	

	for (int i = 0; i < A; i++) {
		q[k] = 'a';
		k++;
	}
	for (int i = 0; i < B; i++) {
		q[k] = 'b';
		k++;
	}
	for (int i = 0; i < C; i++) {
		q[k] = 'c';
		k++;
	}
	for (int i = 0; i < D; i++) {
		q[k] = 'd';
		k++;
	}
	for (int i = 0; i < E; i++) {
		q[k] = 'e';
		k++;
	}
	for (int i = 0; i < F; i++) {
		q[k] = 'f';
		k++;
	}
	for (int i = 0; i < G; i++) {
		q[k] = 'g';
		k++;
	}
	for (int i = 0; i < H; i++) {
		q[k] = 'h';
		k++;
	}
	for (int i = 0; i < I; i++) {
		q[k] = 'i';
		k++;
	}
	for (int i = 0; i < J; i++) {
		q[k] = 'j';
		k++;
	}
	for (int i = 0; i < K; i++) {
		q[k] = 'k';
		k++;
	}
	for (int i = 0; i < L; i++) {
		q[k] = 'l';
		k++;
	}
	for (int i = 0; i < M; i++) {
		q[k] = 'm';
		k++;
	}
	for (int i = 0; i < N; i++) {
		q[k] = 'n';
		k++;
	}
	for (int i = 0; i < O; i++) {
		q[k] = 'o';
		k++;
	}
	for (int i = 0; i < P; i++) {
		q[k] = 'p';
		k++;
	}
	for (int i = 0; i < Q; i++) {
		q[k] = 'q';
		k++;
	}
	for (int i = 0; i < R; i++) {
		q[k] = 'r';
		k++;
	}
	for (int i = 0; i < S; i++) {
		q[k] = 's';
		k++;
	}
	for (int i = 0; i < T; i++) {
		q[k] = 't';
		k++;
	}
	for (int i = 0; i < U; i++) {
		q[k] = 'u';
		k++;
	}
	for (int i = 0; i < V; i++) {
		q[k] = 'v';
		k++;
	}
	for (int i = 0; i < W; i++) {
		q[k] = 'w';
		k++;
	}
	for (int i = 0; i < X; i++) {
		q[k] = 'x';
		k++;
	}
	for (int i = 0; i < Y; i++) {
		q[k] = 'y';
		k++;
	}
	for (int i = 0; i < Z; i++) {
		q[k] = 'z';
		k++;
	}
	if (k == 0)cout << " " << endl;

	for (int i = 0; i < k; i++) {
		cout << q[i];
	}
	return 0;
}