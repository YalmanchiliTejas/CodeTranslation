//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int N,M;
int A;
int B;
int main(){
	cin>>N>>M;
	bool D[10][10]={};
	for(int i=0;i<M;i++){
		cin>>A>>B;
		D[A][B]=true;
		D[B][A]=true;

	}
	bool P[9]={};
	int total=0;
	for(int i1=2;i1<N+1;i1++){
		if(!D[1][i1])continue;
		if(N==2){
			total+=1;
			continue;
		}
		P[i1]=true;
		for(int i2=2;i2<N+1;i2++){
			if(!D[i1][i2] || P[i2])continue;
			if(N==3){
				total+=1;
				continue;
			}
			P[i2]=true;
			for(int i3=2;i3<N+1;i3++){
				if(!D[i2][i3] || P[i3])continue;
				if(N==4){
					total+=1;
					continue;
				}
				P[i3]=true;
				for(int i4=2;i4<N+1;i4++){
					if(!D[i3][i4] || P[i4])continue;
					if(N==5){
						total+=1;
						continue;
					}
					P[i4]=true;
					for(int i5=2;i5<N+1;i5++){
						if(!D[i4][i5] || P[i5])continue;
						if(N==6){
							total+=1;
							continue;
						}
						P[i5]=true;
						for(int i6=2;i6<N+1;i6++){
							if(!D[i5][i6] || P[i6])continue;
							if(N==7){
								total+=1;
								continue;
							}
							P[i6]=true;
							for(int i7=2;i7<N+1;i7++){
								if(!D[i6][i7] || P[i7])continue;
								if(N==8){
									total+=1;
									continue;
								}
								P[i7]=true;
								for(int i8=2;i8<N+1;i8++){
									if(!D[i7][i8] || P[i8])continue;
									if(N==9){
										total+=1;
										continue;
									}
									P[i8]=true;

									P[i8]=false;
								}

								P[i7]=false;
							}

							P[i6]=false;
						}

						P[i5]=false;
					}

					P[i4]=false;
				}

				P[i3]=false;
			}

			P[i2]=false;
		}
		P[i1]=false;
	}

	cout<<total<<endl;

	return 0;
}
