n,q = (int(i) for i in input().split())
now,x = 1,[0 for i in range(n+2)]
x[2] = 1
for i in range(q):
	a,b = (int(j) for j in input().split())
	if a==now or b==now: now=(a+b)-now
	if x[a]==1 and x[b]==1: pass
	elif x[a]==1: x[a],x[b] = 0,1
	elif x[b]==1: x[a],x[b] = 1,0
	x[now+1],x[now-1] = 1,1
x[now] = 1
print(sum(x[1:n+1]))