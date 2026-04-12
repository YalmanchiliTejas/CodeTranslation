import sys
input = sys.stdin.readline
from collections import *

N, X, M = map(int, input().split())
now = X
l = [X]
s = set()
s.add(X)

for i in range(N-1):
    now = now*now%M
    
    if now in s:
        for i in range(len(l)):
            if l[i]==now:
                mark = i
                break
        
        ans = sum(l[:mark])
        siz = len(l)-mark
        tot = sum(l[mark:])
        ans += (N-mark)//siz*tot
        ama = (N-mark)%siz
        
        for i in range(mark, mark+ama):
            ans += l[i]
        
        print(ans)
        exit()
    
    l.append(now)
    s.add(now)

print(sum(l))