#!/usr/bin/env python3
from sys import stdin

def solve():
    x = int(stdin.readline().strip())
    if x==3 or x==5 or x==7:
        print("YES")
    else:
        print("NO")
    pass

solve()