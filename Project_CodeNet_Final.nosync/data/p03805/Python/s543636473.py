from collections import deque
import copy
# https://atcoder.jp/contests/abc054/tasks/abc054_c
# n!の全探索が答えというのは知っているが、自分の開放の誤りを見つけるために自分のやり方でといてみる。

N, M = map(int, input().split())
V = [[] for _ in range(N)]
cont = [0 for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    V[a-1].append([b, copy.deepcopy(cont)])
    V[b-1].append([a, copy.deepcopy(cont)])

# solution
q = deque()
q.append([1, copy.deepcopy(cont)])
count = 0
while q:
    c_v = q.pop()
    c_v[1][c_v[0]-1] = 1
    next_vs = V[c_v[0]-1]
    ifComplete = 1
    for v in next_vs:
        if c_v[1][v[0]-1] == 1:
            continue
        else:
            ifComplete = 0
        # ここで続くvの探索が始まる時に全て訪問されていればcountを増やす。
        # その状態をどうやって管理すればいい？
        v[1] = copy.deepcopy(c_v[1])
        q.append(v)
    # 遷移先のノードが存在しない場合
    if ifComplete:
        flag = 1
        for x in c_v[1]:
            if x == 0:
                flag = 0
                break
        if flag:
            count += 1
print(count)
