import sys

ri = lambda: int(sys.stdin.readline())

n = ri()
print('YES' if n == 3 or n == 5 or n == 7 else 'NO')