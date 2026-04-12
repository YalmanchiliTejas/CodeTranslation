#!/usr/bin/env python3
#ABC107 B

h,w = map(int,input().split())

a = [list(input()) for _ in range(h)]
ans = [['.']*w for _ in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j] == '.':
            for k in range(h):
                if a[k][j] == '.':
                    continue
                else:
                    break
            else:
                for k in range(h):
                    ans[k][j] = None
            for k in range(w):
                if a[i][k] == '.':
                    continue
                else:
                    break
            else:
                for k in range(w):
                    ans[i][k] = None
        if a[i][j] == '#':
            ans[i][j] = '#'
for i in range(h):
    ans[i] = [i for i in ans[i] if i]
for i in range(h):
    if len(ans[i]) != 0:
        print(''.join(ans[i]))
