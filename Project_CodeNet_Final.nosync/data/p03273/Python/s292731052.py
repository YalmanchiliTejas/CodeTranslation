h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]

for i in range(h-1,-1,-1):
    if set(a[i]) == {'.'}:
        del a[i]

for j in range(w-1,-1,-1):
    cnt = 0
    for k in range(len(a)):
        if a[k][j] == '.':
            cnt += 1
    if cnt == len(a):
        for l in range(len(a)):
            del a[l][j]
for i in a:
    print("".join(i))