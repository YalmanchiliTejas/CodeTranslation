l = input().split()
N = int(l[0])
M = int(l[1])

C = [[] for i in range(N)]

for i in range(M):
    l = input().split()
    a = int(l[0]) - 1
    b = int(l[1]) - 1
    C[a].append(b)
    C[b].append(a)

# print(N, M, C)

def visit(cur, visited, ans, depth):
    depth += 1
    # print('depth={}, cur={}, visited={}, ans={}, C[cur]={}'.format(
    #     depth, cur, visited, ans, C[cur]))
    visited.append(cur)
    if len(visited) == N:
        # print('goal')
        return ans + 1
    for n in C[cur]:
        # print('n={}'.format(n))
        if n not in visited:
            v = [x for x in visited]
            ans = visit(n, v, ans, depth)
    return ans

ans = 0
for n in C[0]:
    visited = [0]
    ans += visit(n, visited, 0, 0)

print(ans)
