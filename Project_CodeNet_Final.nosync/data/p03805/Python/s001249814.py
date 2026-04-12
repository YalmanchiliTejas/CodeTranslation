import itertools

n, m = map(int, input().split())

edge = [[0]*n for i in range(n)]

# ２つの頂点間に辺がある時1に、ないときは0に設定する
for i in range(m):
    a, b = map(int, input().split())
    edge[a-1][b-1] = 1
    edge[b-1][a-1] = 1

# 頂点の順列の全てのパターンを[itertools.permutations()]で生成する
# 各並びで辺がない箇所があるかどうかの確認を積で行う
# 全ての頂点間の積が1であれば辺がすべて存在し、そのルートがあるということになる
res = 0
for each in itertools.permutations(range(n)):
    if each[0] != 0:
        break

    x = 1
    for i in range(n-1):
        x *= edge[each[i]][each[i+1]]
    
    res += x

print(res)