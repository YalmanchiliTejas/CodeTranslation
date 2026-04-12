k = str(input())
d = int(input())

DP = [[[0 for _ in range(d)] for _ in range(2)] for _ in range(len(k)+1)]
DP[0][0][0] = 1

for i in range(len(k)):
    now = int(k[i])
    for j in range(2):
        for mod in range(d):
            for n in range(10):
                # 対象の数字未満が確定する場合
                if j==1 or (j==0 and n < now):
                    next_j = 1
                # 対象の数字とこの桁まで同じ場合
                elif n == now:
                    next_j = 0
                # 対象の数字よりも大きな値の場合
                else: 
                    continue

                n_mod = n % d
                next_mod = (mod + n_mod) % d
                DP[i+1][next_j][next_mod] = (DP[i+1][next_j][next_mod] + DP[i][j][mod]) % (10**9+7)

ans = (DP[len(k)][0][0] + DP[len(k)][1][0] -1) % (10**9+7)
print(ans)
# print(DP)
