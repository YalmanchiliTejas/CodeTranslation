#!/usr/bin/python

from sys import stdin

X, Y, Z = map(int, stdin.readline().split())

# 13 3 1
# X >= (Y + Z) * n + Z
# (X - Z) / (Y + Z) >= n

print((X - Z) // (Y + Z))
