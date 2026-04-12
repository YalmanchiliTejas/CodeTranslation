n,x = map(int,input().split())

A = [1]
P = [1]
for i in range(n):
	A.append(A[i]*2+3)
	P.append(P[i]*2+1)
# print(A,P)

def func(n,x):
	if x == 1:
		return 0 if n != 0 else 1
	elif x <= 1+A[n-1]:
		return func(n-1,x-1)
	elif x == 2+A[n-1]:
		return P[n-1]+1
	elif x <= 2+2*A[n-1]:
		return P[n-1]+1+func(n-1,x-2-A[n-1])
	else:
		return 2*P[n-1]+1

print(func(n,x))