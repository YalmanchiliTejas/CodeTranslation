h,w=map(int,input().split())
lst=list(input() for i in range(h))
n_h=h
for i in range(len(lst)):
    if "#" not in lst[h-i-1]:
        n_h-=1
        lst.pop(h-i-1)
lst=list(map(list,lst))
for i in range(w):
    T=True
    for b in range(n_h):
        if lst[b][w-i-1]=="#":
            T=False
            break
    if T:
        for b in range(n_h):
            lst[b].pop(w-i-1)
for a in lst:
    print("".join(a))