S = input()
K = int(input())

l = len(S)

dp0 = [[0 for j in range(K + 1)] for i in range(l + 1)] #　以下未確定
dp1 = [[0 for j in range(K + 1)] for i in range(l + 1)] # 以下確定

dp0[0][0] = 1
for i in range(l):
    n = int(S[i])
    for j in range(K + 1):
        for d in range(10):
            nk = j
            if j > K: # j == Kの場合は残りがすべて0なら配れるので
                continue

            if d > 0:
                nk += 1
                if nk > K:
                    continue
            # 確定済みdp1の配り
            dp1[i + 1][nk] += dp1[i][j]

            #　非確定dp0の配り
            if d > n:
                continue
            elif d == n:
                dp0[i + 1][nk] += dp0[i][j]
            elif d < n:
                dp1[i + 1][nk] += dp0[i][j]

print(dp0[-1][-1] + dp1[-1][-1])









