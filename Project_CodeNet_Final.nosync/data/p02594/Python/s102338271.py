import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


x = int(readline())

print('Yes' if x >= 30 else'No')
