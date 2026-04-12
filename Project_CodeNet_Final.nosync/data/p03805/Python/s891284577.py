# ABC054C
# 方針：階乗の全探索

import itertools
N, M = map(int, input().split())
# Graph の作成
graph = [[] * N for _ in range(N)]
for i in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)

# パターンの全列挙
num_lst = [_ for _ in range(0, N)]
search_list = itertools.permutations(num_lst)

ans = 0
for lst in search_list:
    flag = True
    if lst[0] != 0:    # 1度でも先頭が0以外ならそれ以降は全てダメ
        break
    for i in range(N-1):
        if lst[i+1] in graph[lst[i]]:   # 今の数字が次の数字と繋がっているかどうか
            pass
        else:
            flag = False
            break
    if flag:
        ans += 1

print(ans)