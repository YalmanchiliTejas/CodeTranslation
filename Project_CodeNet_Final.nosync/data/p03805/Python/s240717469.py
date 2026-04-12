# 頂点および辺の数を入力
N, M = map(int, input().split())
# 辺のリストを作成
list_edge = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    list_edge[a].append(b)
    list_edge[b].append(a)

# パスの数を返す関数を定義
def count_path(node, path, list_edge, N):
    # パスの数を初期化
    count = 0
    # 全ての頂点を訪問した場合、、
    if len(path) == N:
        # パスの数に1を加える
        count += 1
    # 全ての頂点を訪問していない場合、、
    else:
        # 現在の頂点から訪問できる各頂点について、、
        for next_node in list_edge[node]:
            # その頂点にまだ訪問していない場合、、
            if next_node not in path:
                # 再帰
                count += count_path(next_node, path + [next_node], list_edge, N)
    # パスの本数を返す
    return count
# パスの本数を出力する
print(count_path(1, [1], list_edge, N))