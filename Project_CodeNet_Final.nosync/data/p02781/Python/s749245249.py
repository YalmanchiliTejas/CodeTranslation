import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = sr()
K = ir()
length = len(N)
top = int(N[0])
dp_dec = [[0] * 4 for _ in range(length)]
dp_pen = [[0] * 4 for _ in range(length)]
dp_dec[0][1] = (top-1)
dp_dec[0][0] = 1
dp_pen[0][1] = 1
#print(dp_dec)
for i in range(1, length):
    cur = int(N[i])
    if cur == 0:
        dp_pen[i] = dp_pen[i-1][:] #右端に0
    else:
        for k in range(1, 4):
            dp_pen[i][k] = dp_pen[i-1][k-1] #右端にcur

    dp_dec[i] = dp_dec[i-1][:] #0が右端に加わった場合
    for j in range(1, 4):
        #print('for', i, j, dp_dec)
        dp_dec[i][j] += dp_dec[i-1][j-1] * 9 #1~9が右端に加わった場合
        if cur > 0:
            dp_dec[i][j] += dp_pen[i-1][j-1] * (cur-1) + dp_pen[i-1][j]
    #print(i, dp_dec)

answer = dp_dec[length-1][K] + dp_pen[length-1][K]
print(answer)
