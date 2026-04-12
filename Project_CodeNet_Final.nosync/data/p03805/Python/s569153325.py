N, M = map(int, input().split())
adj_matrix = [[0]* N for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    adj_matrix[a-1][b-1] = 1
    adj_matrix[b-1][a-1] = 1

def dfs(v, used):
    if not False in used:       # chek complete or not
        return 1

    ans = 0
    for i in range(N):           # check all edge
        if not adj_matrix[v][i]: # edge check
            continue
        if used[i]:              # used check
            continue

        used[i] = True           #　使用済みを示す
        ans += dfs(i, used)
        used[i] = False          # ほかのエッジのためにFalseにする

    return ans

used = [False] * N
used[0] = True

print(dfs(0, used))
