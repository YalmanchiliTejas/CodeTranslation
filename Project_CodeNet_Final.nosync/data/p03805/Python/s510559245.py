from collections import deque

N, M = map(int, input().split())
adj = [[] for _ in range(N)] #隣接している街のリストを作る
for i in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    adj[a].append(b)
    adj[b].append(a)

def DFS(now, visited):
    global ans
    if len(visited) == N:
        ans += 1 #到着したら1回増やす
    else:
        for u in adj[now]:
            if u not in visited: #向かう道の中で訪れていない場所を攻める
                DFS(u, visited+[u])
                #もしappendにすると、visitedが他のルートを選んだ時
                #まえのvisitedを引きずってしまう
        return



ans = 0
visited = [0] #到達したところを記憶していく
DFS(0, visited)
print(ans)