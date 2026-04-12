N=int(input())
A=list(map(int,input().split()))

Ans=0
S=[0]*(len(A)+1)

for i in range(0,N):
  S[i+1]=S[i]+A[i]
  #print(S[i+1])
  
#print(S[N])  
  
for i in range(0,N):
#  print(A[i]*(S[N]-S[i+1]))
  Ans+=A[i]*(S[N]-S[i+1])
  
print(Ans%(10**9+7))

  