# -*- coding: utf-8 -*-

# input
X, Y, Z = map(int, input().split())

# solve
ans = 0
for i in range(1, 50000):
    if Y * i + Z * (i + 1) <= X:
        ans += 1
    else:
        break

# output
print(ans)
