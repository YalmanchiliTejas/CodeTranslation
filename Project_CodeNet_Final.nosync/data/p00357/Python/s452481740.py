n = int(input())
a = [int(input()) for i in range(n)]

ok = True
rg = range(n)
l = 0
for i,d in zip(rg,a):
    if i*10 > l:
        ok = False
        break
    if l >= (n-1)*10:
        break
    if i*10+d > l:
        l = i*10+d

a.reverse()
l = 0
for i,d in zip(rg,a):
    if i*10 > l:
        ok = False
        break
    if l >= (n-1)*10:
        break
    if i*10+d > l:
        l = i*10+d

if ok:
    print('yes')
else:
    print('no')
