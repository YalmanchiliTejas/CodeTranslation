N, X = map(int,input().split())

a = [1 for i in range(N+1)]
p = [1 for i in range(N+1)]
for i in range(1,N+1):
	a[i] = 3 + 2 * a[i-1]
	p[i] = 1 + 2 * p[i-1]

def f(i,X):
	if i == 0 and X == 1:
		return 1
	elif X == 1:
		return 0
	elif X <= a[i-1]+1:
		return f(i-1,X-1)
	elif X == a[i-1]+2:
		return p[i-1]+1
	elif X <= 2*a[i-1]+2:
		return f(i-1,X-(a[i-1]+2)) + p[i-1] + 1
	elif X == 2*a[i-1]+3:
		return 2*p[i-1] + 1
print(f(N,X))
