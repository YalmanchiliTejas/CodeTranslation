import itertools
n, m = map(int, input().split())
edge = [[0 for i in range(n)] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    edge[a-1][b-1] = 1
    edge[b-1][a-1] = 1

def ok(l):
    return all([edge[l[i]-1][l[i+1]-1] for i in range(n-1)])
ans = 0
for x in itertools.permutations(range(2,n+1)):
    l = [1] + list(x)
    if ok(l):
        ans += 1
print(ans)