N, M = map(int, input().split())
E = [[0 for i in range(N)] for j in range(N)] #頂点のつながり
for i in range(M):
    a, b = map(int, input().split())
    E[a-1][b-1] = 1
    E[b-1][a-1] = 1

V = [ 0 for i in range(N)] #訪問済みの頂点が1
V[0] = 1 #頂点1は訪問済み

def DPS(now, V):
    res = 0 #全て訪問できた回数
    if 0 not in V:
        return 1
    for i in range(N): 
        if (E[now][i] == 1) and (V[i] == 0): #現在の頂点と隣接してかつ未訪問の頂点
            V[i] = 1
            res = res + DPS(i, V)
            V[i] = 0
    return res

print(DPS(0, V))