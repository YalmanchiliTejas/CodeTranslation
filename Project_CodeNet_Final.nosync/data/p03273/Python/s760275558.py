h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
for i in range(h):
    if set(a[h-i-1]) == {'.'}:
        del(a[h-i-1])
for i in range(w):
    if set([j[w-i-1] for j in a]) == {"."}:
        for j in a:
            del(j[w-i-1])
for i in a:
    print(''.join(i))