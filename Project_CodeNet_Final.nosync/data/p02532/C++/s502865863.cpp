#include <stack>
#include <iostream>
#include <string>
using namespace std;
 
int main(){
    	int n, p, p1, p2;
	cin >> n;
	string order, color, c;
	stack<string> stack[n+1];
	while(1){
        	cin >> order;
       		if(order=="quit"){
        	    	break;
       		}
        	else if(order=="push"){
            		cin >> p >> color;
            		stack[p].push(color);
        	}
		else if(order=="move"){
			cin >> p1 >> p2;
			c = stack[p1].top();
			stack[p2].push(c);
			stack[p1].pop();
		}
		else if(order=="pop"){
			cin >> p;
			cout << stack[p].top() << endl;
            		stack[p].pop();
        	}
    	}
    return(0);
}