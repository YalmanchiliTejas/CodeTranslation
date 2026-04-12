n,x,m = map(int, input().split())
b = x%m
add = 0

# nがm以下なら全部足せば良い
ans = 0
if n <= m:
    for i in range(n):
        ans += b    
        b = pow(b,2,m)
    print(ans)
    exit()

# nがmより大のとき、効率化
cnt = 0
while 2 ** cnt < m:
    cnt += 1

# 位数と初期値を出す
s = set()
tmp = 0
for i in range(m):
    if i < cnt:
        add += b
        tmp = b
    else:
        s.add(b)
    b = pow(b, 2, m)

# cnt以降、和*位数+残りの和で計算
rest = (n-cnt)%len(s)
div = (n-cnt)//len(s)

rep = []
for i in range(len(s)):
    tmp = pow(tmp, 2, m)
    rep.append(tmp)

ans = add + sum(rep)*div + sum(rep[:rest])
print(ans)