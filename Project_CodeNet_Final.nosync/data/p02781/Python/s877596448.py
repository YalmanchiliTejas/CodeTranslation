n = list(input())
k = int(input())
t = len(n)
ketaDP = [[[0 for i in range(2)] for j in range(k+1)] for u in range(t)]
#ketaDP = [上から何桁目][0以外が何回出てる][nより小さいの確定？]
ketaDP[0][0][0] = 1
ketaDP[0][1][0] = int(n[0])-1
ketaDP[0][1][1] = 1
for i in range(1,t):
    now = int(n[i])
    for j in range(k+1):
        ketaDP[i][j][0] += ketaDP[i-1][j][0]
    for j in range(k):
        ketaDP[i][j+1][0] += ketaDP[i-1][j][0] * 9
    if now == 0:
        for j in range(k+1):
            ketaDP[i][j][1] += ketaDP[i-1][j][1]
    elif now != 0:
        for j in range(k+1):
            ketaDP[i][j][0] += ketaDP[i-1][j][1]
        for j in range(k):
            ketaDP[i][j+1][1] += ketaDP[i-1][j][1]
            ketaDP[i][j+1][0] += ketaDP[i-1][j][1]*(now-1)
print(sum(ketaDP[t-1][k]))
        