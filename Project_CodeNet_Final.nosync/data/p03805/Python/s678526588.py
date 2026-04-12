from itertools import permutations

n, m = map(int, input().split())

tu = [[] for j in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    tu[a].append(b)
    tu[b].append(a)

na = [i for i in range(2,n+1)]
ans = 0

for nara in permutations(na):
    st = 1
    f = True
    for i in range(n-1):
        if not nara[i] in tu[st]:
            f = False
        st = nara[i]
    if f == True:
        ans += 1



print(ans)