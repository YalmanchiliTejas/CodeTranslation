a,b,c,x,y = map(int,input().split())
if x > y:
	z = a
else:
	z = b

ans1 = min(x,y) * min(a + b,c*2) + abs(x-y) * z
ans2 = c * max(x,y) * 2
print(min(ans1,ans2))