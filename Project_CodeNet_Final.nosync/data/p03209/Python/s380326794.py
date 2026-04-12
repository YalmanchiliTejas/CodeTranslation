N,K=map(int,input().split())

thickness=[1]*(N+1)
Npatty=[1]*(N+1)

for i in range(1,N+1):
  thickness[i]=2*thickness[i-1]+3
  Npatty[i]=2*Npatty[i-1]+1

#print(thickness,Npatty)  
def countpatty(N,K):
  if K==1:
    if N==0:
      return 1
    else:
      return 0
  if 2<=K<=thickness[N-1]+1:
    return countpatty(N-1,K-1)
  if K==thickness[N-1]+2:
    return Npatty[N-1]+1
  if thickness[N-1]+3<=K<=thickness[N]-1:
    return Npatty[N-1]+1+countpatty(N-1,K-2-thickness[N-1])
  if K==thickness[N]:
    return 2*Npatty[N-1]+1

print(countpatty(N,K))