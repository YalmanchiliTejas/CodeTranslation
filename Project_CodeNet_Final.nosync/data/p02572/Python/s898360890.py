N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7

s = sum(A)
key = 0
for i in range(N):
    s -= A[i]
    key += s*A[i]
print(key % mod)