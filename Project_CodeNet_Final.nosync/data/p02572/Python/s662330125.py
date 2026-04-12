N = int(input())
A = [int(i) for i in input().split()]

L = len(A)
total = 0
tmp = 0
mod = 10**9+7
for y in range(L):
    tmp += A[y]

for x in range(L):
    tmp -= A[x] 
    total += tmp*A[x]
print(total % mod)
