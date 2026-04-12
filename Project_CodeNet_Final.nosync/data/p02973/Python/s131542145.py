n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))

stack = []

def bisect(li, i):
    if len(li)==0:
        li.append(i)
        return
    ok = len(li)
    ng = -1
    while abs(ok-ng)>1:
        tmp = (ok+ng)//2
        if li[tmp]<i:
            ok = tmp
        else:
            ng = tmp
    if ok < len(li):
        li[ok] = i
    else:
        li.append(i)

for i in a:
    bisect(stack, i)
print(len(stack))