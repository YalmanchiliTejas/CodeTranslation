h , w = map(int, input().split())
a = [list(input()) for _ in range(h)]
good_r = [False for _ in range(h)]
good_c = [False for _ in range(w)]

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            good_r[i] = True
            good_c[j] = True

for i in range(h):
    if good_r[i]:
        string = ''
        for j in range(w):
            if good_c[j]:
                string += a[i][j]
        if len(string) > 0:
            print(string)