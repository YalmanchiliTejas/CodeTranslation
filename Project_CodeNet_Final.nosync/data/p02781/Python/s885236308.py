
"""dp1,2[i][j] 
i桁で0をj個含む数で, 
dp1→ Nの上からi桁目までを抽出した数より小さい
dp2→ Nの上からi桁目までを抽出した数に等しい
"""

N = int(input())
K = int(input())
digit = len(str(N))
N_str = str(N)

dp1 = [[0]*4 for _ in range(digit+1)]
dp2 = [[0]*4 for _ in range(digit+1)]

dp2[0][0] = 1

for i in range(1, digit+1):
    for j in range(4):
        if int(N_str[i-1]) != 0:
            if j >= 1:
                dp2[i][j] = dp2[i-1][j-1]
                dp1[i][j] = dp1[i-1][j]+9*dp1[i-1][j-1]+dp2[i-1][j]+dp2[i-1][j-1]*(int(N_str[i-1])-1)
            else:
                dp1[i][j] = dp1[i-1][j]+dp2[i-1][j]
        else:
            dp2[i][j] = dp2[i-1][j]
            if j >= 1:
                dp1[i][j] = dp1[i-1][j]+9*dp1[i-1][j-1]
            else:
                dp1[i][j] = dp1[i-1][j]

        #print(i, j, dp1[i][j], dp2[i][j])

ans = dp1[digit][K]+dp2[digit][K]

print(ans)
