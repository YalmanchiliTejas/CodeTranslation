h, w = map(int, input().split())
a = []
ac = [0 for i in range(w)]
for i in range(h):
    temp = list(input())
    for j in range(w):
        if temp[j] == '#':
            ac[j] += 1
    if '#' in temp:
        a.append(temp)
    else:
        h -= 1
for j in range(h):
    ans = ''
    for i in range(w):
        if ac[i] != 0:
            ans += a[j][i]
    print(ans)
