import numpy as np


n = int(input())
l = [[0] * (ord('z') - ord('a') + 1) for _ in range(n)]
for i in range(n):
    S = input()
    for s in S:
        idx = ord(s) - ord('a')
        l[i][idx] += 1
l = np.array(l)
l = np.rot90(l, -1)
ans = ''
for j in range(len(l)):
    num = min(l[j])
    ans += chr(ord('a') + j) * num
print(ans)