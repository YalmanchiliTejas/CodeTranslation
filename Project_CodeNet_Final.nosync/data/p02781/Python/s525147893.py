s = list(input())
n = len(s)
k = int(input())
#dp1[i][j] := i桁目まで確定させ、j個0でないものを使った後に、nより小さいことが確定している
#dp2[i][j] := i桁目まで確定させ、j個0出ないものを使った後に、nより小さいことが確定していない
dp1 = [[0 for i in range(k+1)] for j in range(n+1)]
dp2 = [[0 for i in range(k+1)] for j in range(n+1)]
dp1[0][0] = 1
dp1[0][1] = int(s[0]) - 1
dp2[0][1] = 1
for i in range(1,n):
    dp1[i][0] = 1
    for j in range(1,k+1):
        x = int(s[i])
        if x != 0:
            #今回の数字を使うと、確定していないものは確定しない
            dp2[i][j] += dp2[i-1][j-1]
            dp1[i][j] += dp1[i-1][j-1] * 9 + dp2[i-1][j-1] * (x-1)
            dp1[i][j] += dp1[i-1][j] + dp2[i-1][j]
        else:
            dp1[i][j] += dp1[i-1][j-1] * 9 + dp1[i-1][j]
            dp2[i][j] += dp2[i-1][j]
print(dp1[n-1][k] + dp2[n-1][k])