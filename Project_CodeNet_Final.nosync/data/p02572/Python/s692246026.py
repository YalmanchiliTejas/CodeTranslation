N = int(input())
A = list(map(int, input().split()))

prefix = [0]
for a in A:
    prefix.append(prefix[-1] + a)

res = 0
M = 10 ** 9 + 7
for i, a in enumerate(A[:-1], start=1):
    res += a * (prefix[N] - prefix[i])
    res %= M
print(res)