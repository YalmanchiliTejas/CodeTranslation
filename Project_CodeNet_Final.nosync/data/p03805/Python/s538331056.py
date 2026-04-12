# coding: utf-8
# Your code here!

def dfs():
    path = 1
    lst_path = []
    lst_path.append((0, path))
    cnt = 0
    while len(lst_path) > 0:
        node, path = lst_path.pop()
        for i in G[node]:
            if not path & (1 << i):
                if path + (1 << i) == -1 + (1 << N):
                    cnt += 1
                    continue
                lst_path.append((i, path + (1 << i)))
    return cnt

N, M = map(int, input().split())
G= [[] for i in range(N)] 
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
    
result = dfs()
print(result)


