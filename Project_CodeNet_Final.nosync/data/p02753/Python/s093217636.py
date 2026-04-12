import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

S = read().rstrip()
print('Yes' if len(set(S)) == 2 else 'No')