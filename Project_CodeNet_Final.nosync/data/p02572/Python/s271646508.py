N=int(input())
K=[int(n) for n in input().split()]
S=sum(K)
total=0
for i in range(N):
  S-=K[i]
  total+=K[i]*S
print(total %(10**9+7))