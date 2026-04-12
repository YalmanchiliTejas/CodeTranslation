x,a,b = map(int,input().split())
l = -1
r = 10**18+1
while r - l > 1 :
	c = (r + l) // 2
	sum = (a - b) * c + a
	if sum >= x : r = c
	else : l = c
if x <= a : print(1)
elif r != 10**18+1 : print(2 * r + 1)
else : print(-1)