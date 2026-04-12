#include<iostream>
using namespace std;
int main(){
while(1){
int judge;
int maxscore =0;
int minscore =0;
cin >> judge;
if(judge != 0){
int score[judge];
	for(int i=0; i<judge; i++){
	cin >> score[i];
		if(score[i] > maxscore){
		maxscore = score[i];
		}
		if(score[i] < minscore){
		minscore = score[i];
		}
		if(i==0){
		minscore = score[0];
		}
	}
int lastscore = 0;
for(int j=0;j<judge;j++){
lastscore +=  score[j];
}
lastscore = (lastscore - maxscore - minscore)/(judge - 2);
cout << lastscore <<endl;
}else
break;
}
return 0;
}