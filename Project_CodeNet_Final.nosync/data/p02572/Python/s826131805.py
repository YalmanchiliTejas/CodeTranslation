N=int(input())
A=list(map(int,input().split()))
#437235829 mod(10^9+7)
sumAcol=0
sumA=0
sumtr=0
for i in range(N):
  sumtr+=A[i]**2
  sumAcol+=A[i]
  sumtr=sumtr % (10**9+7)
  sumAcol=sumAcol % (10**9+7)

for i in range(N):
  sumA+=(sumAcol*A[i])%(10**9+7)
  
sumA=(sumA-sumtr)+10**9+7

print(sumA*(5*10**8+4) % (10**9+7))

