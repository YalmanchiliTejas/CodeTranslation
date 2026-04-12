import sys
input=sys.stdin.readline

N,M = map(int, input().split())

# E[i] := 頂点 i と結ばれている頂点の集合
E = [set() for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    E[a].add(b)
    E[b].add(a)

ans = 0

# まだ訪れていない頂点を訪れていき、全て訪問できたら +1.
# 現在地 n, 次の候補の集合 nexts, 訪問済みの集合 visited
def dfs(n, nexts, visited):
    v = visited + [n]
    if len(v) == N:
        global ans
        ans += 1
    else:
        for i in nexts:
            dfs(i, set([j for j in E[i] if j not in v]), v)

def main():
    dfs(1, E[1], [])
    print(ans)
    
if __name__ == '__main__':
    main()
