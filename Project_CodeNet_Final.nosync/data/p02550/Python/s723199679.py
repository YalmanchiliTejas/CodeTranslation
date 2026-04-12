#ダブリング解
n, x, m = map(int, input().split())
tmp = [None]*m
for i in range(m):
    tmp[i] = i*i%m
pos = [tmp]
accu = [tmp]
for i in range(40):
    tmp1 = [None]*m
    tmp2 = [None]*m
    for j in range(m):
        tmp1[j] = pos[-1][pos[-1][j]]
        tmp2[j] = accu[-1][pos[-1][j]] + accu[-1][j]
    pos.append(tmp1)
    accu.append(tmp2)
now = x
ans = x
for i in range(40):
    if (n-1)>>i&1:
        ans += accu[i][now]
        now = pos[i][now]
print(ans)