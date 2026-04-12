#include <iostream>
using namespace std;

int search(int a,int b,int c,int p)
{
	p += (a/3+b/3+c/3);
	int tta = a%3;
	int ttb = b%3;
	int ttc = c%3;
	int ttp = p;
	while(tta!=0 && ttb!=0 && ttc!=0){
		ttp++;
		tta--;ttb--;ttc--;
	}

	int ta = a%3;
	int tb = b%3;
	int tc = c%3;
	int tp = p;
	if(ta==2 || tb==2 || tc==2){
		if(ta==0 && ta+3 <= a){
			tp--;
			ta+=3;
		}
		if(tb==0 && tb+3 <= b){
			tp--;
			tb+=3;
		}
		if(tc==0 && tc+3 <= c){
			tp--;
			tc+=3;
		}
	}
	while(ta!=0 && tb!=0 && tc!=0){
		tp++;
		ta--;tb--;tc--;
	}
	return max(ttp,tp);
}

int main()
{
	int a,b,c,d,e,f;
	while(cin >> a >> b >> c >> d >> e >> f){
		if(!a && !b && !c && !d && !e && !f)
			break;
		cout << search(a+d,b+e,c+f,0) << endl;
	}
	return 0;
}