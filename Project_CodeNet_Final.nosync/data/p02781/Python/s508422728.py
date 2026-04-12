n = str(input())
k = int(input())

DP = [[[0 for _ in range(k+1)] for _ in range(2)] for _ in range(len(n)+1)]
DP[0][0][0] = 1

for i in range(len(n)):
    now = int(n[i])
    for j in range(2):
        for non_zero in range(k+1):
            for m in range(10):
                if j == 1 or (j == 0 and m < now):
                    next_j = 1
                elif m == now:
                    next_j = 0
                else:
                    continue

                if non_zero == k and m != 0:
                    continue
                elif m == 0:
                    next_non_zero = non_zero
                else:
                    next_non_zero = non_zero + 1
                
                DP[i+1][next_j][next_non_zero] += DP[i][j][non_zero]

ans = DP[len(n)][1][k] + DP[len(n)][0][k]
print(ans)
# print(DP)

