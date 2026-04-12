N = int(input())
A = list(map(int,input().split()))

su = sum(A) % (10**9+7)
ans = 0

for i in range(N):
    ans += ((su - A[i]) * A[i]) % (10**9+7)
    su -= A[i]

print(ans % (10**9+7))