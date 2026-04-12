N, M = map(int, input().split())

g = [[False for i in range(N)] for j in range(N)]
for i in range(M):
    a, b = map(lambda x:int(x)-1, input().split())
    g[a][b] = g[b][a] = True

def print_set(s):
    for e in s:
        print(e + 1, end=" ")
    print()

checker = N*(N - 1)//2
cnt = 0
def dfs(visited: set, stack: list):
    global cnt
    if sum(list(visited)) == checker:
        cnt += 1
    elif len(stack) > 0:
        v = stack.pop()
        for i in range(N):
            if g[v][i] and not (i in visited):
                dfs(visited | set([i]), stack + [i])

dfs(set([0]), [0])
print(cnt)