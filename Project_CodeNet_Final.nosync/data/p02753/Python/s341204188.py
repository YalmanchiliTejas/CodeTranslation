def solve():
	ar=input()
	a=0
	b=0
	for i in ar:
		if(i=='A'):
			a+=1
		else:
			b+=1;
	if(a==0 or b==0):
		print("No");
	else:
		print("Yes");			
t=1
#t=int(input())
while(t>0):
	solve()
	t-=1
		
	
