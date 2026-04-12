from itertools import permutations
n, m = map(int, input().split())
pair = [tuple(map(int, input().split())) for i in range(m)]
num = [i for i in range(1,n+1)]
ans = 0
for p in permutations(num):
    if p[0] != 1:
        continue
    already = []
    state = True
    for i in range(n-1):
        if p[i] in already:
            state = False
            break
        if (min(p[i], p[i+1]), max(p[i], p[i+1])) not in pair:
            state = False
            break
        already.append(p[i])
    if state:
        ans += 1
print(ans)
