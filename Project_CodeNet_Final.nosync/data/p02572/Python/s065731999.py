N = int(input())
A = list(map(int,input().split()))
ans = 0
suma = sum(A)
for i in range(N-1):
    suma -= A[i]%(10**9+7)
    ans += (A[i] * suma )%(10**9+7)
print(ans%(10**9+7))