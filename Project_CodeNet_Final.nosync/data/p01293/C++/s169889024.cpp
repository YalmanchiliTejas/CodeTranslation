#include <iostream>

using namespace std;

struct card
{
	int rank;
	char suit;
};

int main(void)
{
	char trump;
	char led;
	string s;
	card c[4][13];
	int maxx,maxS;
	int NS,EW;
	int i1,i2;

	while(1){
		cin>>trump;
		if(trump=='#') break;

		for(i1=0;i1<4;i1++){
			for(i2=0;i2<13;i2++){
				cin>>s;
				if('2'<=s[0] && s[0]<='9') c[i1][i2].rank=s[0]-48;
				else if(s[0]=='A') c[i1][i2].rank=14;
				else if(s[0]=='T') c[i1][i2].rank=10;
				else if(s[0]=='J') c[i1][i2].rank=11;
				else if(s[0]=='Q') c[i1][i2].rank=12;
				else c[i1][i2].rank=13;

				c[i1][i2].suit=s[1];
			}
		}

		NS=-6;
		EW=-6;
		for(i1=0;i1<13;i1++){
			maxx=0;
			if(i1==0) led=c[0][0].suit;
			else led=c[maxS][i1].suit;
			for(i2=0;i2<4;i2++){
				if(trump==c[i2][i1].suit) c[i2][i1].rank+=26;
				else if(led==c[i2][i1].suit) c[i2][i1].rank+=13;
				
				if(maxx<c[i2][i1].rank){
					maxx=c[i2][i1].rank;
					maxS=i2;
				}
			}
			if(maxS%2==0) NS++;
			else EW++;
		}

		if(NS>EW) cout<<"NS "<<NS<<endl;
		else cout<<"EW "<<EW<<endl;
	}
	return 0;
}