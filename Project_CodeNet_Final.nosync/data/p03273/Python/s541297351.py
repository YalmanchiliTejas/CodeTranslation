import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

h, w = map(int, readline().split())
a = [input() for i in range(h)]
ans = []
memo_x = []
memo_y = []
for i in range(h):
    cnt = 0
    for j in range(w):
        if a[i][j] == '.':
            cnt += 1
    if cnt == w:
        memo_x.append(i)
for i in range(w):
    cnt = 0
    for j in range(h):
        if a[j][i] == '.':
            cnt += 1
    if cnt == h:
        memo_y.append(i)
for i in range(h):
    if i not in memo_x:
        b = ''
        for j in range(w):
            if j not in memo_y:
                b += a[i][j]
        ans.append(b)
for i in range(len(ans)):
    print(ans[i])
