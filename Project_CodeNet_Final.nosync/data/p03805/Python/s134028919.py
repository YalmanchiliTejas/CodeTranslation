import sys
sys.setrecursionlimit(4100000)

def Dfs(G, v, n, visited):
    all_visited = True
  
    for i in range(n):
      if visited[i] == False:
        all_visited = False
 
    if all_visited:
        return 1
 
    ret = 0
 
    for i in range(n):
        if not G[v][i]:
            continue
        if visited[i]:
            continue
        visited[i] = True
        ret += Dfs(G, i, n, visited)
        visited[i] = False
 
    return ret

 
def main():
    input =  sys.stdin.readline
    n, m = map(int, input().split())
    e = [list(map(int, input().split())) for i in range(m)]
    g = [[False for j in range(n)] for i in range(n)]
    for i, j in e:
        g[i-1][j-1] = True
        g[j-1][i-1] = True
    visited = [False for i in range(n)]
    visited[0] = True
    
    print(Dfs(g, 0, n, visited))

if __name__ == "__main__":
    main()
