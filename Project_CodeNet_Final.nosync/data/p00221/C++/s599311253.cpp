#include<iostream>
#include<cstring>
#include<sstream>

struct person{
	int num;
	struct person *prev;
	struct person *next;
};

struct person *head,*p,*now;
int m,n;
char s[128];

void set(){
	for(int i=0; i<m; i++){
		p[i].num = i+1;
		p[i].prev = p+i-1;
		p[i].next = p+i+1;
	}
	p[0].prev = p+m-1;
	p[m-1].next = p;
}

void del(struct person *a){
		(a->prev)->next = a->next;
		(a->next)->prev = a->prev;
		if(a == head)
			head = a->next;
}

void show(struct person *a){
	std::cout << a->num;
	if(a->next == head)
		return;
	else{
		std::cout << ' ';
		show(a->next);
	}
}

int main(){
	while(true){
		std::cin >> m >> n;
		if(!m && !n)
			return 0;
		p = new struct person[m];
		head = p;
		now = head;
		set();
		for(int i=0; i<n; i++){
			std::cin >> s;
			if(now == now->next){
				continue;
			}else if((i+1)%15 == 0){
				if(strcmp(s,"FizzBuzz") != 0)
					del(now);
			}else if((i+1)%3 == 0){
				if(strcmp(s,"Fizz") != 0)
					del(now);
			}else if((i+1)%5 == 0){
				if(strcmp(s,"Buzz") != 0)
					del(now);
			}else{
				std::string str(s);
				std::istringstream ss(str);
				int a = 0;
				ss >> a;
				if(a != i+1)
					del(now);
			}
			now = now->next;
		}
		show(head);
		std::cout << std::endl;
		delete[] p;
	}
}