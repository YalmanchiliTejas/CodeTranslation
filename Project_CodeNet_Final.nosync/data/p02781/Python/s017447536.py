from copy import deepcopy


def make_multi_list(initial, degree):
    ans = [initial for _ in range(degree[-1])]
    for d in reversed(degree[:-1]):
        ans = [deepcopy(ans) for _ in range(d)]
    return ans


dp = make_multi_list(initial=0, degree=[105, 4, 2])
dp[0][0][0] = 1

S = input().strip()
K = int(input())
n = len(S)

for i in range(n):
    for j in range(4):
        for k in range(2):
            nd = int(S[i])
            for d in range(10):
                ni = i + 1
                nj = j
                nk = k
                if d != 0:
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[ni][nj][nk] += dp[i][j][k]

ans = dp[n][K][0] + dp[n][K][1]
print(ans)
