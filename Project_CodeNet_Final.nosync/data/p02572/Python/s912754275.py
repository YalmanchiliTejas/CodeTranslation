N=int(input())
A=list(map(int,input().split()))

listsum=[]
s=0
for i in range(N):
  s+=A[N-1-i]
  listsum.append(s)
  
S=0
for i in range(N-1):
  S+=A[i]*listsum[N-2-i]
  S=S%(10**9+7)
  
print (S)