a, b, c, x, y = map(int, input().split())
# ピザの枚数a,b,cについては
# 2c = a+b が成り立つ
# cを奇数個買ってもこの問題の場合意味がないので基本2cで考える

ans = float('inf')
# cをi枚買ったとする。
# x,y <= 10^5 なので100000+1回しとけば問題なし
for i in range(100001):
    ans = min(ans, (2*c)*i + a*max(x-i,0) + b*max(y-i,0))
print(ans)