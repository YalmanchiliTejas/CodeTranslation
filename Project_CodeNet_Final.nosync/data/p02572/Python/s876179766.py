import sys

def mmul(a,b):
	return ((a%m)*(b%m))%m

def madd(a,b):
	return (a%m+b%m)%m

def msub(a,b,):
	return (a%m-b%m+m)%m

N=int(sys.stdin.readline())

A=[int(i) for i in sys.stdin.readline().split()]

m=pow(10,9)+7

pre=[0]

for h in range(N):
	pre.append(madd(A[h],pre[h]))

ans=0

for p in range(N-1):
	val=mmul(A[p],msub(pre[N],pre[p+1]))
	ans=madd(ans,val)

print(ans)

