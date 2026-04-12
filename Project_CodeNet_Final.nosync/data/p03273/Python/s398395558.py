h, w = map(int, input().split())
a = [list(input()) for _ in [0]*h]
for j in range(w):
    if not any(a[i][j]=='#' for i in range(h)):
        for i in range(h):
            a[i][j] = ''
for i in a:
    if any(j=='#' for j in i):
        print(''.join(i))