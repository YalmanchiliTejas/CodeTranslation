import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

x = int(input())

if x >= 30:
    print('Yes')
else:
    print('No')