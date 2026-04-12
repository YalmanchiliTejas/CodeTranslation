N = int(input())
A = list(map(int,input().split()))

a = sum(A)
a *= a

for i in range(N):
  a -= A[i]*A[i]
  
print(a//2%(10**9+7))