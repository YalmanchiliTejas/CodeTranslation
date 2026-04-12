import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
s = readline()

if 'A' in s and 'B' in s:
    print('Yes')
else:
    print('No')