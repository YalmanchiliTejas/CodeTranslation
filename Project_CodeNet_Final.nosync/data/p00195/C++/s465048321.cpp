#include <iostream>
using namespace std;

int main()
{
	char n[5] = {'A','B','C','D','E'};
	int a[5],b[5];
	int name,max;
	while(cin >> a[0] >> b[0]){
		if(a[0] == 0 && b[0] == 0)
			break;
		max = a[0]+b[0];
		name = 0;
		for(int i=1;i<5;i++){
			cin >> a[i] >> b[i];
			if(max < a[i]+b[i]){
				max = a[i]+b[i];
				name = i;
			}
		}
		cout << n[name] << " " << max << endl;
	}
	return 0;
}