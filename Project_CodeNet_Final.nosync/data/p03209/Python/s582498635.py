import numpy as np
n, x = map(int, input().split())

l = np.zeros(51, dtype=np.int64)
p = np.zeros(51, dtype=np.int64)

for i in range(n + 1):
    if i == 0:
        l[i] = 1
        p[i] = 1
        continue
    l[i] = 3 + 2 * l[i - 1]
    p[i] = 1 + 2 * p[i - 1]

ans = 0
for i in range(n, -1, -1):
    layer = l[i]
    if x >= layer:
        ans += p[i]
        break
    elif x <= 1:
        break

    half = l[i - 1] + 1
    if x > half:
        ans += 1
        ans += p[i - 1]
        x -= half
        x -= 1
    elif x <= half:
        x -= 1

print(ans)
