# xとyどっちを優先にするか
# -> これだとなんかできそうでできない ABピザとハイブリッドしたほうが得な場合もありそう（多分
# 「ABピザをいくつ使うか」固定して全探索してみる

a, b, c, x, y = map(int, input().split())
ans = 10**18
for i in range(2 * 10**5 + 100):
    # ABピザi枚使ったとする（奇数枚はありえないので2倍
    p = 2 * c * i + a * (max(0, x - i)) + b * (max(0, y - i))
    # print(f"ABピザを{2*i}枚使ったよ p={p}")
    ans = min(ans, p)
print(ans)