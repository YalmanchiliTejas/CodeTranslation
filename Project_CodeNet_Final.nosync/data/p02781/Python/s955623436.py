n = [int(c) for c in input()]
k = int(input())
dp0 = [1, n[0] - 1] + [0 for j in range(2, k + 1)]
dp1 = [0, 1] + [0 for j in range(2, k + 1)]
for i in range(2, len(n) + 1):
    for j in range(k, 0, -1):
        dp0[j] = (dp0[j - 1] * 9 + dp0[j] + dp1[j - 1] * max(n[i - 1] - 1, 0)
                  + dp1[j] * int(n[i-1] != 0))
    if n[i - 1] != 0:
        dp1 = [0] + dp1[:-1]
print(dp0[-1] + dp1[-1])
