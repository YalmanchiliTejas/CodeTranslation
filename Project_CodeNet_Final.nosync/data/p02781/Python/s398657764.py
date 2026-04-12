n = input()
k = int(input())
digit = len(n)
dp0 = [[0 for i in range(k+1)] for j in range(digit+1)]
dp1 = [[0 for i in range(k+1)] for j in range(digit+1)]

dp1[1][1] = 1
dp0[1][1] = int(n[0])-1
for i in range(1, digit+1):
    dp0[i][0] = 1

for i in range(2, digit+1):
    for j in range(1, k+1):
        num = int(n[i-1])
        if num == 0:
            dp0[i][j] = dp0[i-1][j-1]*9 + dp0[i-1][j]
            dp1[i][j] = dp1[i-1][j] 
        else:
            dp0[i][j] = dp0[i-1][j-1]*9 + dp0[i-1][j] + dp1[i-1][j-1] * (num-1) + dp1[i-1][j]
            dp1[i][j] = dp1[i-1][j-1]

print(dp0[digit][k] + dp1[digit][k])