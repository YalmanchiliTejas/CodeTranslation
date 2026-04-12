import copy

N,M = map(int, input().split())
T = [[] for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    T[a].append(b)
    T[b].append(a)

def search(s, V):
    ans = 0
    if s in V:
        return 0
    Vc = copy.copy(V)
    Vc.add(s)
    if Vc == set(list(range(1, N+1))):
        return 1
    for v in T[s]:
        ans += search(v, Vc)
    return ans

print(search(1, set()))