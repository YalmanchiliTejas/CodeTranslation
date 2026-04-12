import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

x = int(readline())
print('YES' if x in [3, 5, 7] else 'NO')
