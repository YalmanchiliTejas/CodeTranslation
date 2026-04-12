# -*- coding: utf-8 -*-

# 関数定義
def dfs(now_p, visited, comb_p, p_num):
    # N頂点と同じ数のルートを通ったら有効なパスとして1を返す
    if len(visited) == p_num:
        return 1

    ans = 0

    # now_pの検索
    for tmp_p in comb_p:
        if tmp_p[0] == now_p and tmp_p[1] not in visited:
            # visitedのtmp
            tmp_visited = visited[:]
            tmp_visited.append(tmp_p[1])
            #print(*tmp_visited)
            # 次の頂点
            next_p = tmp_p[1]
            #print('next_p: ', next_p)
            # comb_pのtmp
            tmp_comb = comb_p[:]
            tmp_comb.remove(tmp_p)
            # 往復対象の削除
            tmp_p_r = [tmp_p[1], tmp_p[0]]
            tmp_comb.remove(tmp_p_r)
            #print(*tmp_comb)
            # dfsの再起呼び出し
            ans += dfs(next_p, tmp_visited, tmp_comb, p_num)

    return ans

## 入力読み取り
N, M = map(int, input().split())
a_b = []
tmp = []
tmp_r = []

# 辺読み取り
for i in range(M):
    tmp = list(map(int, input().split()))
    tmp_r = [tmp[1], tmp[0]]
    a_b.append(tmp)
    a_b.append(tmp_r)

visited = [1]

# 再起関数の実施
pass_num = dfs(1, visited, a_b, N)
print(pass_num)