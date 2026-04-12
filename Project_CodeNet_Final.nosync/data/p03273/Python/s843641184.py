h,w = map(int,input().split())
a = [input() for _ in range(h)]
for i in range(h-1,-1,-1):
    if set(a[i])=={'.'}: a.remove(a[i])
for i in range(w-1,-1,-1):
    ok = True
    for j in range(len(a)):
        if a[j][i]=='#': ok=False
    if ok:
        for j in range(len(a)):
            a[j] = a[j][:i]+a[j][i+1:]
[print(i) for i in a]