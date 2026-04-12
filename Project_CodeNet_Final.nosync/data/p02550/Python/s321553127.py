n, x, m = map(int,input().split())
k = (x ** 2) % m
l = [0] * (m+1)
l[(x ** 2) % m] == 0
a = [x]
flag = True
for i in range(n-1):
    x = (x ** 2) % m
    a.append(x)
    if l[x] != 0:
        flag = False
        break
    else:
        l[x] += 1
    
    

if not flag:
    p = i+1
    ku = n - p 
    f = False
    loops = []
    for i in range(len(a)-1):
        if f:
            loops.append(a[i])
        else:
            if (a[i]) == a[-1]:
                loops.append(a[i])
                p = len(a) - (i+1)
                f = True
    k = max(1, len(loops))
    w = (ku) // k
    x = (ku) % k


if flag:
    ans = sum(a)
else:
    sss = 0
    for i in range(x):
        sss += loops[i]
    ans = sum(a) - a[-1] + sum(loops) * w + sss
print(ans)