import itertools

N, M = map(int, input().split())
adj_mtrx = [[0] * N for _ in range(N)]

# 隣接行列
for i in range(M):
    a, b = map(int, input().split())
    # 無向グラフなので両方1にする
    adj_mtrx[a-1][b-1] = 1
    adj_mtrx[b-1][a-1] = 1


cnt = 0

# itertools.permutations(list) リストから順列を生成、列挙
# 頂点を結ぶ結び方を全て列挙する（順列で列挙できる）
# 列挙したした中で頂点1から始まっているかつパスとして繋がっているものをカウントする
for each in itertools.permutations(range(N)):

    # 1からスタートしない場合break
    if each[0]!=0:
        break

    factor=1
    for i in range(N-1):
        # 隣接行列で繋がっていれば1、繋がっていなければ0なので
        # 一つでも繋がっていなければ、0になる
        factor *= adj_mtrx[each[i]][each[i+1]]
    cnt += factor

print(cnt)
