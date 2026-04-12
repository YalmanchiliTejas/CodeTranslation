def dfs(parent, connect, passed, N): #深さ優先探索
    cnt = 0
    passed.append(parent) #通った点をメモ
    if len(passed) == N: #全ての点を通過したかの判定
        cnt = 1
    for next_ in connect[parent]:
        if next_ in passed:
            continue
        cnt += dfs(next_, connect, passed, N) #全ての点を通るまで再帰. 戻り値の和で何通りかカウント
    passed.pop() #分岐点に戻る前にメモを1段だけ破棄
    return cnt    

N, M = map(int, input().split())
connect = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    connect[a-1].append(b-1)
    connect[b-1].append(a-1)
ans = dfs(0, connect, [], N) #点0からのdfs
print(ans)