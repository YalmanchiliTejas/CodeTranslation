a,b,c,x,y = map(int,input().split())
ans = 10**9
for i in range(max(x,y)+1):
	cost = c*2*i+a*max(0,x-i)+b*max(0,y-i)
	ans = min(cost,ans)
print(ans)
