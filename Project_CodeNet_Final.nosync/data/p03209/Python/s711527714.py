n, x = map(int, input().split())
x -= 1
npl = [0] * (n+1)
lbl = [0] * (n+1)
npl[0] = 1
lbl[0] = 1
for i in range(1, n+1):
    npl[i] = 2*npl[i-1] + 1
    lbl[i] = 2*lbl[i-1] + 3

ans = 0
while n >= 0:
    n -= 1
    if x == 0:
        # 左端
        if n == -1:
            ans += 1
        break
    elif 1 <= x <= lbl[n]:
        # 左側
        x -= 1
    elif lbl[n]+1 == x:
        # 真中
        ans += npl[n] + 1
        break
    elif lbl[n]+1 < x < 2*lbl[n]+2:
        # 右側
        x -= lbl[n]+2
        ans += npl[n]+1
    elif x == 2 + 2*lbl[n]:
        # 右端
        ans += 2*npl[n] + 1

print(ans)
