L,X=map(int,input().split())
b=[1];p=[1]
for i in range(L):
	b.append(b[-1]*2 + 3)
	p.append(p[-1]*2 + 1)
def f(L, X):
	if L==0 or X<0:
		return 0 + (X>0)
	elif X <= 1 + b[L-1]:
		return f(L-1, X-1)
	else:
		return p[L-1] + 1 + f(L-1, X-b[L-1]-2)
print(f(L, X))
