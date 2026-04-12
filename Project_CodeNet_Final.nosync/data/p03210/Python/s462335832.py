#!/usr/bin/env python3
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
s = int(input())
if s in [3,5,7]: print("YES")
else: print("NO")