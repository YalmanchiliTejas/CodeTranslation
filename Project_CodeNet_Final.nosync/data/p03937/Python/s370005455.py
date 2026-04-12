import sys
input = sys.stdin.readline

h, w = map(int, input().split())
a = [input().rstrip('\n') for i in range(h)]
cnt = 0

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            cnt += 1

if cnt == h + w - 1:
    print('Possible')
else:
    print('Impossible')
