n, m = map(int, input().split())
vertex = [[0] * n for _ in range(n)]
edge = []
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge.append([a, b])
    vertex[a][b] = 1
    vertex[b][a] = 1

check = [0] * n
check[0] = 1


def dfs(x):
    ans = 0
    if min(check) == 1:  # 全ての探索が完了した時
        return 1  # 1を返す。
    for i in range(n):  # n個の頂点から一つずつ取り出して
        if vertex[x][i] == 1 and check[i] == 0:  # 頂点xから頂点iに移動でき、かつ未探索の時
            check[i] = 1  # 探索済みにする
            ans += dfs(i)  # pathの本数を加える
            check[i] = 0  # 未探索に戻す
    return ans  # pathの本数を出力する


print(dfs(0))
