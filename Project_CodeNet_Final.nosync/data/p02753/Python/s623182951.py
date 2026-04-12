#!/usr/bin/python3
import sys
input = lambda: sys.stdin.readline().strip()
s = input()
print('No' if s == 'AAA' or s == 'BBB' else 'Yes')