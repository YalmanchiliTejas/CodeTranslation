import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
S = readline().decode()
if 'A' in S and 'B' in S:
    print('Yes')
else:
    print('No')