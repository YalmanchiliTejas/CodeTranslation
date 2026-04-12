h, w = map(int, input().split())

cnt = 0
for i in range(h):
    cnt += input().count('#')

if (h + w - 1) == cnt:
    print('Possible')
else:
    print('Impossible')