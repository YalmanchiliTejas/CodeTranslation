a,b,c,x,y = map(int,input().split())
ans = a*x + b*y
for i in range(max(x,y) + 1):
	money = max(0,(x-i)*a) + max(0,(y-i)*b) + 2*i*c
	if money <= ans:
		ans = money
print(ans)