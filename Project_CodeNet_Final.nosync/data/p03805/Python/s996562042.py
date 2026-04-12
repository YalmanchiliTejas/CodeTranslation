def search(node):
    global ans

    if sum(is_visit) == n:
        ans += 1

    for i in range(n):
        if is_neighbor[node][i]:
            if not is_visit[i]:
                is_visit[i] = True
                search(i)
                is_visit[i] = False

n, m = map(int, input().split())

is_neighbor = [[False for j in range(n)] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    is_neighbor[a - 1][b - 1] = True
    is_neighbor[b - 1][a - 1] = True

is_visit = [False for _ in range(n)]

ans = 0

is_visit[0] = True
search(0)
print(ans)