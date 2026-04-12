a,b = map(int,input().split(" "))
ar = []
br = [[] for i in range(b)]
for i in range(a):
    l = list(input())
    if "#" in l:
        ar.append(l)
    for j in range(b):
        br[j].append(l[j])
cr = []
for i,r in enumerate(br):
    if "#" not in r:
        cr.append(i)
er = [[] for i in range(len(ar))]
for i in range(len(ar)):
    for j in range(b):
        if j not in cr:
            er[i].append(ar[i][j])
for r in er:
    print("".join(r))

