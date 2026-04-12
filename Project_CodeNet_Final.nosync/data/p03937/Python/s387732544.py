h, w = map(int, input().split())
cnt = 0
for i in range(h):
    ai = input()
    for j in range(w):
        if ai[j] == '#':
            cnt += 1

if cnt == h+w-1:
    print('Possible')
else:
    print('Impossible')