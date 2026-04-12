n ,x = map(int, input().split())
B=[1]
P=[1]
for i in range(n):
	B.append(2*B[i]+3)
	P.append(2*P[i]+1)

def cnt(n,x):
	if n==0 and x<=0:
		return 0
	if n==0 and x>=1:
		return 1
	m=(B[n]+1)//2
	if x<m:
		return cnt(n-1,x-1)
	elif x==m:
		return P[n-1]+1
	elif x>m:
		return P[n-1]+1+cnt(n-1, x-m) 

print(cnt(n,x))
	