from sys import stdin
S = list(stdin.readline().rstrip())
if len(set(S)) != 1:
    print('Yes')
else:
    print('No')