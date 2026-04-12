import sys
a, b, c = map(int, sys.stdin.readline().split())
print ["NO", "YES"][(b * 10 + c) % 4 == 0]
