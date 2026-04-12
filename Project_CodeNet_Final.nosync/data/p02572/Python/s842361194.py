N=int(input())
A=list(map(int,input().split()))
A=A[::-1]
P=0
C=0
for i in range(N):
  P+=A[i]*C
  C+=A[i]
print(P%(10**9+7))
