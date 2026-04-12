#!/usr/bin/env python3
from sys import stdin

def solve():
    n, x = map(int, stdin.readline().split())
    items = []
    items.append([1,1])
    for i in range(1,n+1):
        items.append([items[-1][0]*2+3, items[-1][1]*2+1])
    
    if x<=n:
        print(0)
        return
    
    ans = 0
    p = n
    while p and x:
        half = (items[p][0]+1)//2
        if x>=half:
            ans += items[p-1][1] + 1
            x -= half
        else:
            x -= 1
        p -= 1

    if x:
        ans += 1
    print(ans)

solve()