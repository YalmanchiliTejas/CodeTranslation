h, w = map(int, input().split())
tmp = 0
for _ in range(h):
    tmp += input().count('#')
if tmp == h+w-1:
    print('Possible')
else:
    print('Impossible')
