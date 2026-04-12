import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = sr()
K = ir()
length = len(N)
top = int(N[0])
dp_de = [[0] * 4 for _ in range(length)] #decided
dp_pend = [[0] * 4 for _ in range(length)] #pending
dp_de[0][1] = (top-1)
dp_de[0][0] = 1
dp_pend[0][1] = 1
for i in range(1, length):
    cur = int(N[i])
    # pend → pend
    if cur == 0:
        dp_pend[i] = dp_pend[i-1][:] #右端に0
    else:
        for k in range(1, 4):
            dp_pend[i][k] = dp_pend[i-1][k-1] #右端にcur

    dp_de[i] = dp_de[i-1][:] #0が右端に加わった場合
    for j in range(1, 4):
        dp_de[i][j] += dp_de[i-1][j-1] * 9 #1~9が右端に加わった場合
        if cur > 0:
            # pendから流れる、右端にcur以下の数が加わった場合と0が加わった場合
            dp_de[i][j] += dp_pend[i-1][j-1] * (cur-1) + dp_pend[i-1][j] * 1 

answer = dp_de[length-1][K] + dp_pend[length-1][K]
print(answer)
