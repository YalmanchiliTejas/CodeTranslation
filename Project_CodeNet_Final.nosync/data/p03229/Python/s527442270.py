n = int(input())
x = [int(input()) for i in range(n)]
x.sort()
if n%2:
	a = 2*sum(x[n-n//2:])-sum(x[n-n//2-2:n-n//2])-2*sum(x[:n-n//2-2])
	a2 = -2*sum(x[:n//2])+sum(x[n//2:n//2+2])+2*sum(x[n//2+2:])
	print(max(a,a2))
else: print(-2*sum(x[:(n-2)//2])-x[(n-2)//2]+x[(n-2)//2+1]+2*sum(x[(n-2)//2+2:]))