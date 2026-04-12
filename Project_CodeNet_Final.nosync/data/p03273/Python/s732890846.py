h,w = map(int,input().split(' '))
A = []
Ilist = [1]*w
for p in range(h):
    a=input()
    if '#' in a:
        A.append(a)
        i = 0
        while i < w:
            if a[i] == '#':
                Ilist[i] *= 0
            i += 1
#Ilist[k] = 1であるkを除外。
ans = ''
for a0 in A:
    k = 0
    while k < w:
        if Ilist[k] == 0:
            ans += a0[k]
        k += 1
    ans += '\n'
print(ans)