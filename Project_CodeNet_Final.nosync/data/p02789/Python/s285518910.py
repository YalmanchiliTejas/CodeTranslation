#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

n, m = [int(item) for item in input().split()]
if n == m:
    print("Yes")
else:
    print("No")