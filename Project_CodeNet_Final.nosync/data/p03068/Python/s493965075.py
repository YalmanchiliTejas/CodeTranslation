N=int(input())
S=input()
K=int(input())
a=""
for s in S:
	a += "*" if s != S[K-1] else s
print(a)
