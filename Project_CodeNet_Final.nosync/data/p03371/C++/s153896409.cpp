    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
    	int a, b, c, x, y;
    	cin >> a >> b >> c >> x >> y;
     
    	int price = 0;
    	price += min(a+b, 2*c)*min(x, y);
     
    	if (x >= y) {
    		price += min(a, 2*c)*(x-y);
    	} else {
    		price += min(b, 2*c)*(y-x);
    	}
     
    	cout << price << endl;
    }