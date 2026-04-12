from itertools import permutations
n, m = map(int, input().split())
pair = [tuple(map(int, input().split())) for i in range(m)]
num = [i+1 for i in range(n)]
box = []
for p in permutations(num):
    if p[0] == 1:
        box.append(p)
ans = 0
for p in box:
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
