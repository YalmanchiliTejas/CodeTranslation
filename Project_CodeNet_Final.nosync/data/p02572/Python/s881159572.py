N=int(input())
A=list(map(int,input().split()))

S=sum(A)
a=0
for x in A:
  S-=x
  a+=S*x
    
MOD=10**9+7
print(int(a%MOD))
  

