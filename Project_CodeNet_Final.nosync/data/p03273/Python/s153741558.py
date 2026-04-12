H,W = map(int,input().split())
a = []
for i in range(H):
    x = list(input())
    if '#' in x:
        a.append(x)
def trans(a):
    x = [i for i in zip(*a)]
    return x
at = trans(a)
an = []
for i in at:
    if '#' in i:
        an.append(i)
ans = trans(an)
for i in ans:
    print(*i,sep = '')