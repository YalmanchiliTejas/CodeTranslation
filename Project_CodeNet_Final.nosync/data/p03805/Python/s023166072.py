N, M = map(int, input().split())
open_list = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    open_list[a].append(b)
    open_list[b].append(a)

# 探索済みリスト
closed_list = [False] * N
closed_list[0] = True
cnt = 0
level = 1

# 深さ優先探索
def dfs(target):
    global cnt, level
    if all(closed_list):
        cnt += 1
        return
    # open_listリストのnode
    for node in open_list[target]:
        # 探索済みでない場合
        if closed_list[node] is False:
            # 探索開始
            closed_list[node] = True
            # 再帰
            level += 1
            dfs(node)
            level = 1
            # levalを戻す
            closed_list[node] = False
    return


dfs(0)
print(cnt)
