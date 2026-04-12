import sys
input = sys.stdin.readline

S = input().rstrip('\r')
count = [0, 0]
for s in S:
    if (s == 'A'): count[0] = 1
    if (s == 'B'): count[1] = 1
if count[0] == 1 and count[1] == 1:
    print('Yes')
else:
    print('No')