a,b,c,x,y=[int(i)  for i in input().split()]
ans=1000000000
for k in range(10**5+1):
	money=2*c*k + max(x-k,0)*a + max(y-k,0)*b
	if(ans>money):
		ans=money
print(ans)


