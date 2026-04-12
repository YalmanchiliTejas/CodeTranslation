# -*- coding: utf-8 -*-

# input
r, g, b = map(int, input().split())

# solve
ans = 'YES' if (100 * r + 10 * g + b) % 4 == 0 else 'NO'

# output
print(ans)
