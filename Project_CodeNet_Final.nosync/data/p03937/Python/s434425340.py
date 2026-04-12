h, w = map(int, input().split())
a = [input() for _ in range(h)]
cnt = 0
for i in range(h):
    cnt += a[i].count('#')
if cnt == h + w - 1:
    print('Possible')
else:
    print('Impossible')