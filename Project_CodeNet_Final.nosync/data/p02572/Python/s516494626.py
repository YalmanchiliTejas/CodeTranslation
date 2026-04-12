n=int(input())
A=list(map(int, input().split()))
ao=10**9+7

zt=sum(A)**2
for _ in A:
  zt -= _**2
  
zt=(zt//2)%ao
print(zt)