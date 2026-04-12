from itertools import permutations

n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

perm = permutations(list(range(2, n+1)), n - 1)

ans = 0
for p in perm:
    flag = True
    for i in range(n-1):
        if i == 0:
            if not [1, p[i]] in ab:
                flag = False
                break
        else:
            if not ([p[i-1], p[i]] in ab or [p[i], p[i-1]] in ab):
                flag = False
                break
    if flag: ans += 1
print(ans)

