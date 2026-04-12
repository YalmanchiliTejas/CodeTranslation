h, w = map(int, input().split())

cnt = 0

for _ in range(h):
    s = input()
    cnt += s.count('#')

if (h+w - 1) == cnt:
    print('Possible')
else:
    print('Impossible')