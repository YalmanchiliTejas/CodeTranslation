#include "iostream"
#include "string"
using namespace std;
int d[6]={1,2,3,4,5,6},tmp;
int north()
{
	tmp=d[0];
	d[0]=d[1];
	d[1]=d[5];
	d[5]=d[4];
	d[4]=tmp;
	return d[0];

}
int east()
{
	tmp=d[0];
	d[0]=d[3];
	d[3]=d[5];
	d[5]=d[2];
	d[2]=tmp;
	return d[0];

}
int south()
{
	tmp=d[0];
	d[0]=d[4];
	d[4]=d[5];
	d[5]=d[1];
	d[1]=tmp;
	return d[0];

}
int west()
{
	tmp=d[0];
	d[0]=d[2];
	d[2]=d[5];
	d[5]=d[3];
	d[3]=tmp;
	return d[0];

}
int left()
{
	tmp=d[1];
	d[1]=d[3];
	d[3]=d[4];
	d[4]=d[2];
	d[2]=tmp;
	return d[0];

}
int right()
{
	tmp=d[1];
	d[1]=d[2];
	d[2]=d[4];
	d[4]=d[3];
	d[3]=tmp;
	return d[0];

}
int main(void)
{
	int n;
	while (cin>>n,n) {
		for (int i = 0; i < 6; i++) {
			d[i]=i+1;
		}
		string in;
		int ans=1;
		while (n--) {
			cin>>in;
			switch (in[0]) {
				case 'N':
					ans+=north();
					break;
				case 'E':
					ans+=east();
					break;
				case 'S':
					ans+=south();
					break;
				case 'W':
					ans+=west();
					break;
				case 'L':
					ans+=left();
					break;
				case 'R':
					ans+=right();
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}