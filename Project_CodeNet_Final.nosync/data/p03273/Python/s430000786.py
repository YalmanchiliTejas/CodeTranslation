import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

h, w = map(int, readline().split())
a = [readline().rstrip().decode() for i in range(h)]
memo_w = [False] * h
memo_h = [False] * w
for i in range(h):
    flag = True
    for j in range(w):
        if a[i][j] == '#':
            flag = False
            break
    if flag:
        memo_w[i] = True
for i in range(w):
    flag = True
    for j in range(h):
        if a[j][i] == '#':
            flag = False
            break
    if flag:
        memo_h[i] = True
for i in range(h):
    if not memo_w[i]:
        ans = ''
        for j in range(w):
            if not memo_h[j]:
                ans += a[i][j]
        print(ans)
