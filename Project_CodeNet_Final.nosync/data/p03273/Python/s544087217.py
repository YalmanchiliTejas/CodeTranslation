import sys
input = sys.stdin.readline
from collections import *

H, W = map(int, input().split())
a = [input()[:-1] for _ in range(H)]
f = [False]*W

for i in range(W):
    l = []
    
    for j in range(H):
        l.append(a[j][i])
    
    if l==['.']*H:
        f[i] = True

for i in range(H):
    if a[i]=='.'*W:
        continue
    
    ans = []
    
    for j in range(W):
        if not f[j]:
            ans.append(a[i][j])
    
    print(''.join(ans))