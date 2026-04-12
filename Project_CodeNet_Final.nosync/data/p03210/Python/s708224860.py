#!/usr/bin/env python3

import sys

def to_be_celebrate(n):
    if n == '3':
        return True
    if n == '5':
        return True
    if n == '7':
        return True
    return False

X = sys.stdin.readline().rstrip()

print('YES' if to_be_celebrate(X) else 'NO')