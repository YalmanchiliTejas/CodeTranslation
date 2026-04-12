[n,x] = [int(i) for i in input().split()]
ls = [1]
pts = [1]

for i in range(50):
    ls.append(2 * ls[-1] + 3)
    pts.append(2 * pts[-1] + 1)

ans = 0

while n > 0 and x >= 0:
    if x < ls[n]//2:
        x -= 1
        n -= 1
    elif x == ls[n]//2:
        x = -1
        ans += pts[n-1]
    else:
        if x == ls[n]:
            x = 0
            ans += pts[n]
        else:
            x -= ls[n]//2
            ans += pts[n-1]+1
print(ans)
