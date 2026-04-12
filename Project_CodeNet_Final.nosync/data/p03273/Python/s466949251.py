h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]
now = 0
while True:
    if ("#" in a[now]):
        now += 1
    else:
        a.pop(now)
    if (now >= len(a)):
        break
#print(a)
ans = [[] for _ in range(len(a))]
for i in range(w):
    f = 0
    for j in range(len(a)):
        if (a[j][i]=="#"):
            f += 1
    if (f>0):
        for j in range(len(a)):
            ans[j].append(a[j][i])
for i in range(len(a)):
    print(''.join(ans[i]))