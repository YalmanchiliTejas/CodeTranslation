
cnt = 0
H, W = map(int, input().split())
A = [input() for _ in range(H)]

def_cnt = 0
for h in range(H):
    for w in range(W):
        if A[h][w] == '#':
            def_cnt += 1

def dfs(h, w):
    global cnt
    cnt += 1
    if h+1 < H and A[h+1][w] == '#':
        dfs(h+1, w)
    elif w+1 < W and A[h][w+1] == '#':
        dfs(h, w+1)

cnt = 0

if A[0][0] == '.':
    print('Impossible')
    exit()

dfs(0, 0)
if def_cnt == cnt:
    print('Possible')
else:
    print('Impossible')
