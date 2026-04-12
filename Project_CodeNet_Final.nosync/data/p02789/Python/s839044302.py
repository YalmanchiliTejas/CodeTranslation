#!/usr/bin/env python3
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
n,m = map(int,read().split())
if n == m: print("Yes")
else: print("No")