import sys
input = sys.stdin.readline
s=input().rstrip()
if len(set(s))>1:
    print('Yes')
else:
    print('No')

