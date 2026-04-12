//碁石は白→黒…、黒→白…の塊の先頭でしか
//色を変える操作は起こりえない。
//また、色を変えるときには、塊ごと色が変わる。
#include<iostream>
using namespace std;

int N;
int stone[100000];
int sento;
int taba[100000];
int first[100000];

int main(){
	int i,j,tcorsole,ccorsole = 0;
	int count[1000] = {0};
	while(1){
		tcorsole = 0;
		cin >> N;
		if(N == 0)
			break;
		for(i = 0;i < N;i++){
			cin >> stone[i]; 
			taba[i] = 1;
		}
		sento = stone[0];
		first[0] = 0;
		for(i = 0;i < N-1;i++){
			if(stone[i+1] == stone[i]){
				taba[tcorsole]++;
			}
			else{
				tcorsole++;
				first[tcorsole] = i+1;
			}
		}
		//もちろん碁石をひっくり返す順番は昇順
		for(i = 1;i <= tcorsole;i++){
			if(first[i]%2 == 0)
				continue;
			//碁石を同じ色の石があるとこまでひっくり返す
			for(j = i-1;j >= 0;j--){
				if((i-j)%2 == 0){
					if(taba[j] != 0)
						break;
				}
				else{
					taba[i] += taba[j];
					taba[j] = 0;
				}
			}
		}
		for(i = 0;i <= tcorsole;i++){
			if((i+sento)%2 == 0)
				count[ccorsole] += taba[i];
		}
		ccorsole++;
	}
	for(i = 0;i < ccorsole;i++){
		cout << count[i] << endl;
	}
	return 0;
}