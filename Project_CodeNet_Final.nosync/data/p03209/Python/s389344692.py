n,x = map(int,input().split())
x -= 1

p = [1]
l = [1]
for i in range(n):
    p.append(p[-1]*2+1)
    l.append(l[-1]*2+3)

res = 0
while n >= 0:
    if n == 0:                 # レベル1のバーガーはこれ以上細分化できない
        res += 1
        break
    elif x == 0:               # 左端
        break
    elif x == l[n] - 1:        # 右端
        res += p[n]
        break
    elif x == l[n] // 2:       # 中心
        res += p[n-1] + 1
        break
    elif x > l[n] // 2:        # 1個包含している
        res += p[n-1] + 1
        x -= l[n-1] + 2
        n -= 1
    else:                      # 包含していない
        n -= 1
        x -= 1

print(res)
