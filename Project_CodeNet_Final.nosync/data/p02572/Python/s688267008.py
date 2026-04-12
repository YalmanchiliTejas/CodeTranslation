N = int(input())
A = list(map(int, input().split()))

ans = 0
tmp = sum(A)
for i in range(N):
    tmp -= A[i]
    ans += A[i] * tmp
    ans = ans % (10 ** 9 + 7)

print(ans)