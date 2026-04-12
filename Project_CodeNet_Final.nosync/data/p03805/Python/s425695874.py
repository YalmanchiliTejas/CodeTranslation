import itertools
n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

data = [i for i in range(2, n+1)]

ans = 0
for a in itertools.permutations(data, n-1):
    a = [1] + list(a)
    flag = True
    for i in range(1, len(a)):
        if not ([a[i-1], a[i]] in ab or [a[i], a[i-1]] in ab):
            flag = False
            break
    if flag:
        ans += 1
print(ans)
