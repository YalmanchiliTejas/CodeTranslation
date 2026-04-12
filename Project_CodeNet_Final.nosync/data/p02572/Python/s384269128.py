N = int(input())
A = list(map(int,input().rstrip().split(" ")))
k = [0 for i in range(N + 1)]
ans = 0
for i in range(N):
    k[i + 1] = k[i] + A[i]
for i in range(N):
    ans += k[i] * A[i]
    ans %= 10 ** 9 + 7
print(ans)