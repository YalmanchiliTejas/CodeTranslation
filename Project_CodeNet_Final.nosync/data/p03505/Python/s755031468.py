#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

k, a, b = [int(item) for item in input().split()]
if a >= k:
    print(1)
    exit()
if abs(a) - abs(b) <= 0:
    print(-1)
    exit()
diff = abs(a) - abs(b)
print(1 + (k - a + diff - 1) // diff * 2)