import sys

X = sys.stdin.readline().rstrip()
if len(set(X)) > 1:
    print('Yes')
else:
    print('No')
