n,x,m = map(int, input().split())

#xに何番目にきたかを記録していく。-1じゃなければ一回以上きている
table = [-1] * m
extra = []
l = 0
total = 0
#table[x]は周期が始まる点
while table[x] == -1:
    
    extra.append(x)
    table[x] = l
    l += 1
    total += x
    x = (x*x) % m 

#周期の長さ
c = l - table[x]

#周期の和
s = 0
for i in range(table[x], l):
    s += extra[i]

ans = 0

#周期がnより長い場合
if n <= l:
    for i in range(n):
        ans += extra[i]
else:
    #最初の一週目を足す
    ans += total
    n -= l
    #残りの周期の周の和を足す
    ans += s*(n//c)
    n %= c

    for i in range(n):
        ans += extra[table[x]+i]

print(ans)
