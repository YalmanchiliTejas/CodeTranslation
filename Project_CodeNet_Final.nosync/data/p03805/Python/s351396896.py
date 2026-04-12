# -*- coding: utf-8 -*-
N, M = map(int, input().split(' '))

graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split(' '))
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

is_used = [False for _ in range(N)]
is_used[0] = True
buf = [(0, is_used)]
ans = 0

while buf:
    src, is_used = buf.pop()
    if all(is_used):
        ans += 1

    else:
        for dst in graph[src]:
            if not is_used[dst]:
                is_used2 = list(is_used)
                is_used2[dst] = True
                buf.append((dst, is_used2))

print(ans)


