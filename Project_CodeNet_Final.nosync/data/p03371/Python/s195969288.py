"""
CでAやBが0.5枚できる分だけ買う意味はないので、必ず一枚作れるように買う
X,Yが 10**5までなので、Cで何枚作るか決めて、残りをA、B単品で埋めた時のコストの最小値を全探索
"""

A,B,C,X,Y  = map(int, input().split())


ans = float("inf")
# iはCで何枚のA,Bを作るか
for i in range(max(X,Y)+1):
    # C買う分のコスト
    cost = 2*i*C
    # 残りのAのコスト
    if i < X:
        cost += (X-i)*A
    # 残りのBのコスト
    if i < Y:
        cost += (Y-i)*B
    ans = min(ans, cost)

print(ans)