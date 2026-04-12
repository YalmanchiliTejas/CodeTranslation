N,M = map(int, input().split())

# 繋がっている点を記載する二重リストを準備する。
adj_matrix = [[0]* N for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    adj_matrix[a-1][b-1] = 1
    adj_matrix[b-1][a-1] = 1

# 点を通ったかを記録するリスト
used = [False] * N
used[0] = True


# 深さ探索を行うため再帰関数を定義する。
# 現在いる点をvとしての再帰
def dfs(v, used):
    # 再帰を繰り返してusedの中身が全てTrueになったときのみ1を返すようにする。
    if not False in used:
        return 1

    ans = 0
    for i in range(N):
        if adj_matrix[v][i] != 1:
            continue
        if used[i]:
            continue
        used[i] = True
        ans += dfs(i, used)
        used[i] = False
    # usedの中にFalseがあるとき用のreturn(再帰で用いられるようのreturn)
    return ans

print(dfs(0, used))

        

