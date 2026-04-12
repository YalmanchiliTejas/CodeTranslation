from collections import deque


h, w = map(int, input().split())
a = [input() for i in range(h)]

q = deque([(0, 0)])
while q:
    i, j = q.pop()
    cnt = 0
    if i == h - 1 and j == w - 1:
        break
    for nxt_i, nxt_j in [(i + 1, j), (i, j + 1)]:
        if not(0 <= nxt_i < h and 0 <= nxt_j < w):
            continue
        if a[nxt_i][nxt_j] == "#":
            cnt += 1
            q.append((nxt_i, nxt_j))
    if cnt != 1:
        print("Impossible")
        exit()

cnt = 0
for i in range(h):
    cnt += a[i].count("#")
if cnt != h + w - 1:
    print("Impossible")
else:
    print("Possible")