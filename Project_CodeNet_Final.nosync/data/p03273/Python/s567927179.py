h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
tmp = 0
cnt = 0

for i in range(h):
    if ''.join(a[i-tmp]) == '.'*w:
        del a[i-tmp]
        tmp += 1

for i in range(w):
    lst = []
    for j in range(h-tmp):
        lst.append(a[j][i-cnt])
    if ''.join(lst)=='.'*(h-tmp):
        for k in range(h-tmp):
            del a[k][i-cnt]
        cnt += 1

for i in range(h-tmp):
    print(''.join(a[i]))