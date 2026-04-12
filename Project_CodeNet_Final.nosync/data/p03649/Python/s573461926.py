import numpy as np

n = int(input())
a = np.array(input().split(), np.int64)


def check(x):
    cnt = np.maximum((a + x + 1) // (n + 1), 0)
    return cnt.sum() <= x


l = -1
r = 10 ** 18

while r - l > 1:
    m = (l + r) // 2
    if check(m):
        r = m
    else:
        l = m

for i in range(max(r - (n - 1) * n, 0), r + 1):
    if check(i):
        print(i)
        exit()
