#include<iostream>

using namespace std;

int north(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[1];
	dice[1]=d[5];
	dice[2]=d[2];
	dice[3]=d[0];
	dice[4]=d[4];
	dice[5]=d[3];
	return dice[0];
}

int south(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[3];
	dice[1]=d[0];
	dice[2]=d[2];
	dice[3]=d[5];
	dice[4]=d[4];
	dice[5]=d[1];
	return dice[0];
}

int east(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[4];
	dice[1]=d[1];
	dice[2]=d[0];
	dice[3]=d[3];
	dice[4]=d[5];
	dice[5]=d[2];
	return dice[0];
}

int west(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[2];
	dice[1]=d[1];
	dice[2]=d[5];
	dice[3]=d[3];
	dice[4]=d[0];
	dice[5]=d[4];
	return dice[0];
}

int right(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[0];
	dice[1]=d[2];
	dice[2]=d[3];
	dice[3]=d[4];
	dice[4]=d[1];
	dice[5]=d[5];
	return dice[0];
}

int left(int dice[6])
{
	int d[6];
	for(int i=0;i<6;i++)	d[i]=dice[i];
	dice[0]=d[0];
	dice[1]=d[4];
	dice[2]=d[1];
	dice[3]=d[2];
	dice[4]=d[3];
	dice[5]=d[5];
	return dice[0];
}

int main()
{
	for(int n;cin>>n,n;){
		int dice[6]={1,2,3,5,4,6},sum=1;
		while(n--){
			char s[16];	cin>>s;
			switch(s[0]){
				case 'N':	sum+=north(dice);	break;
				case 'E':	sum+=east(dice);	break;
				case 'W':	sum+=west(dice);	break;
				case 'S':	sum+=south(dice);	break;
				case 'R':	sum+=right(dice);	break;
				case 'L':	sum+=left(dice);	break;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}