h, w = map(int, input().split())
lis = [list(input()) for _ in range(h)]
cnt = 0
for i in reversed(range(h)):
    if set(lis[i])=={'.'}:
        lis.pop(i)
        cnt += 1
for j in reversed(range(w)):
    if set([l[j] for l in lis])=={'.'}:
        for k in range(h-cnt):
            lis[k].pop(j)
for m in lis:
    print("".join(m))
