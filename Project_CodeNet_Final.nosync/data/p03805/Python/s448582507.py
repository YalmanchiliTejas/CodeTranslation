from copy import copy
N, M = map(int, input().split())
br = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    br[a-1].append(b-1)
    br[b-1].append(a-1)
ans = 0
stack = []
seen = [False]*N
seen[0] = True
stack.append((0, copy(seen)))
while len(stack):
    n, s = stack.pop()
    f = False
    for m in br[n]:
        if not s[m]:
            s2 = copy(s)
            s2[m] = True
            stack.append((m, s2))
            f = True
    if not f and not False in s:
        ans += 1
print(ans)
