import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

H, W = mapint()
query = [list(input()) for _ in range(H)]

rows = [0]*H
cols = [0]*W
for h in range(H):
    for w in range(W):
        if query[h][w]=='#':
            rows[h] = 1
            cols[w] = 1

for h in range(H):
    if not rows[h]:
        continue
    ans = []
    for w in range(W):
        if cols[w]:
            ans.append(query[h][w])
    print(''.join(ans))