import sys


N=input()
A=[  int(sys.stdin.readline()) for i in range(N) ] 

A.sort()

K=[]
K2=[]

if N%2==0:
	n=(N-2)/2
	K=[ -2 for i in range(n) ]+[-1,1]+[ 2 for i in range(n) ]
else:
	n=(N-2)/2

	## Pattern 1
	K=[ -2 for i in range(n) ]+[-1,-1]+[ 2 for i in range(n+1) ]
	## End

	## Pattern 2
	K2=[ -2 for i in range(n+1) ]+[1,1]+[ 2 for i in range(n) ]
	## End

ans=0

t1=0
for x, y in zip(A,K):
	t1+=x*y

t2=0
for x, y in zip(A,K2):
	t2+=x*y


print max(t1,t2)



