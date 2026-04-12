# abc 158
import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)

S = readline().strip().decode('utf-8')

if len(set(list(S))) == 1:
    print('No')
else:
    print('Yes')

