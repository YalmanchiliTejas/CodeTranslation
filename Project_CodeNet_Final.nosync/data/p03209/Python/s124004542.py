N, X = map(int, input().split())
a = [1]
p = [1]
for i in range(N):
	a.append(a[i]*2+3)
	p.append(p[i]*2+1)

def f(N, X):
	if N == 0:
		return 0 if X <= 0 else 1
	elif X <= a[N-1]+1:
		return f(N-1, X-1)
	elif X == a[N-1]+2:
		return p[N-1] + 1
	elif a[N-1]+3 <= X <= 2*a[N-1]+2:
		return f(N-1, X-2-a[N-1]) + p[N-1] + 1
	else:
		return p[N]

print(f(N, X))
