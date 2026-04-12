a,b,c,x,y = map(int,input().split())
ab = min(a + b,c * 2)
ccc = min(x,y)
ans = ccc * ab
x-=ccc
y-=ccc
if y == 0:
	print(ans + min(x * a,x * ab))
else:
	print(ans + min(y * b,y * ab))