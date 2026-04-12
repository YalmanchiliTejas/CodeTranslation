N, M = map(int, input().split())  #頂点, 辺
g = [[] for _ in range(N)]  #iはjと繋がっている
for _ in range(M):
    a, b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

#1度通った頂点をTrueにする
is_checked = [False] * N

def dfs(i):
    cnt = 0
    is_checked[i] = True
    if not(False in is_checked):
        return 1
    else:
        for j in g[i]:
            if not(is_checked[j]):
                cnt += dfs(j)
                is_checked[j] = False
        return cnt
            
ans = dfs(0)
print(ans)