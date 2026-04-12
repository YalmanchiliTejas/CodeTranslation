h, w = map(int, input().split())
n = 0
for y in range(h):
    s = input()
    for c in s:
        if c == '#':
            n += 1
if n == h + w - 1:
    print('Possible')
else:
    print('Impossible')