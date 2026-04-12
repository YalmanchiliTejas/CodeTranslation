N = int(input())
A = list(map(int, input().split()))

reversed_cumsum = []
tmp = 0
for i in range(N):
    tmp += A[N - 1 - i]
    reversed_cumsum.append(tmp)
cumsum = reversed_cumsum[::-1]

ans = 0
for i in range(N - 1):
    ans = (ans + A[i] * cumsum[i + 1]) % (10 ** 9 + 7)
print(ans)
