N, M = map(int, input().split())
dict = {i+1:[] for i in range(N)}
for _ in range(M):
    a, b = map(int, input().split())
    dict[a].append(b)
    dict[b].append(a)
    
def DFS(visited, sight, cnt):
    if(len(visited) == N):
        return cnt+1
    for num in dict[sight]:
        if num in visited:
            continue
        cnt = DFS(visited+[num], num, cnt)
    return cnt

print(DFS([1], 1, 0))