#include <iostream>
#include <stack>

//[begin, end)がcolor
struct Range{
	int begin, end, color;
};

int main(){
	int n;
	while(std::cin >> n, n){
		std::stack<Range> rs;
		int c;
		std::cin >> c;
		rs.push({0, 1, c});

		for(int i=1;i<n;i++){
			std::cin >> c;

			if(i%2 == 0){
				Range r = rs.top();
				if(c != r.color){
					rs.push({i, i+1, c});
				}else{
					r.end++;
					rs.pop(); rs.push(r);
				}
			}else{
				Range r = rs.top();
				if(c != r.color){
					rs.pop();
					if(!rs.empty()){
						Range pr = rs.top();
						if(c == pr.color){
							rs.pop();
							r.begin = pr.begin;
						}
					}
					r.end++;
					r.color = c;
					rs.push(r);
				}else{
					r.end++;
					rs.pop();rs.push(r);
				}
			}
		}

		int s = 0;
		while(!rs.empty()){
			Range r = rs.top();rs.pop();
			if(r.color == 0){
				s += r.end - r.begin;
			}
		}

		std::cout << s << std::endl;
	}
}