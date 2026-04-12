#!/usr/bin/env python3
import sys

rl = sys.stdin.buffer.readline
INF = sys.maxsize

X = int(rl())

print('Yes' if 30 <= X else 'No')