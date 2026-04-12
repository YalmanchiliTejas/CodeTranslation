#include <bits/stdc++.h>
#include <iostream>
using namespace std;




int main () {

	int h,w;
	int i,j;
	cin>>h>>w;

	vector<vector<char>> cell(h,vector<char>(w));

//input

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin>>cell.at(i).at(j);
		}
	}

//comp==================================
int h_out=h,w_out=w;

//width--------------
bool jdg;
j=0;
while (j<w_out) {

	jdg=true;
	i=0;
	while (i<h) {

		if (cell.at(i).at(j)=='#'){
			jdg=false;
			break;

		}
		i++;
	}

	if (jdg==true) {
		//圧縮
		for (int n=j;n<w_out-1;n++) {
			for (int m=0;m<h_out;m++){

			cell.at(m).at(n)=cell.at(m).at(n+1);

			}
		}

		w_out--;
		j--;//列ずれにより、再度同列検査。
	}
	j++;
}

//hight-------------
i=0;
while (i<h_out) {
	j=0;
	jdg=true;
	while (j<w_out) {
		if (cell.at(i).at(j)=='#') {

			jdg=false;
			break;
		}
		j++;
	}

	if (jdg==true) {
		//ずらし
		for (int m=i;m<h_out-1;m++) {
			for (int n=0;n<w_out;n++) {

				cell.at(m).at(n)=cell.at(m+1).at(n);

			}
		}
		h_out--;
		i--;
	}
	i++;
}

//output============================
for (i=0;i<h_out;i++) {

	for (j=0;j<w_out;j++) {

		cout<<cell.at(i).at(j);
	}
	cout<<endl;
}
}//main








