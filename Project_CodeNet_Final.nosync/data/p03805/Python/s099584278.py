N, M = map(int, input().split())

# それぞれの要素のつながりを1で表現
A = [ [0 for _ in range(N)] for _ in range(N) ]

visited = [False]*N

for i in range(M):
    a, b = map(int, input().split())
    # インデックスのため -1する
    a -= 1
    b -= 1
    A[a][b] = 1
    A[b][a] = 1

def dfs(node, count):
    # 全てのノードが訪れられていたら ans+=1
    if all(visited):
        return count+1
    
    # 全てのノード間の繋がりでfor文
    for i in range(N):
        # nodeの繋がりがあるか判定。
        if A[node][i] == 0:
            continue
        # 見ているノードが訪れられているか判定。
        if visited[i]:
            continue
        
        # 見ているノード間の繋がりがあり、そのノードが訪れられていないとき。
        visited[i] = True
        count = dfs(i, count)
        # 探索前の状態に戻す
        visited[i] = False

    return count

# 開始地点
visited[0] = True

# 開始地点とcountを引数に
count = dfs(0, 0)

print(count)