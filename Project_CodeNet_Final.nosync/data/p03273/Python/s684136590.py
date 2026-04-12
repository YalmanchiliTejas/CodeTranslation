h,w = map(int,input().split())
a = [list(input()) for i in range(h)]
ha = 0
for i in reversed(range(h)):
    if set(a[i])=={"."}:
        a.pop(i)
        ha+=1
for i in reversed(range(w)):
    if set([s[i] for s in a])=={"."}:
        for j in range(h-ha):
            a[j].pop(i)
for ai in a:
    print("".join(ai))