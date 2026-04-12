n = int(input())
slist = [list(input())for i in range(n)]
for s in slist:
    s.sort()

glist = slist[0]

for i in range(1,n):
    new = []
    k = 0
    l = 0
    j = 0
    while (j+k < len(glist)) and (j+l < len(slist[i])):
        if glist[j+k] == slist[i][j+l]:
            new.append(glist[j+k])
            j += 1

        elif glist[j+k] < slist[i][j+l]:
            k += 1

        else:
            l += 1

    glist = new[::]
print("".join(glist))
