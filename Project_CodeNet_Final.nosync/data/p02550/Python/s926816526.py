import sys
N, X, M = map(int, input().split())
ans = X
is_visited = [-1 for i in range(10**5+1)]
X_list = []
for i in range(0, N-1):
    X = (X ** 2) % M
    if is_visited[X] >= 0:
        remN = N-i-1
        ans += (remN // (i-is_visited[X])) * sum(X_list[is_visited[X]:])
        for j in range(is_visited[X], is_visited[X]+remN % (i-is_visited[X])):
            ans += X_list[j]
        print(ans)
        sys.exit()
    is_visited[X] = i
    X_list += [X]
    ans += X
    if X == 0:
        print(ans)
        sys.exit()
print(ans)

    
