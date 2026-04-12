N = int(input())
Hlist = list(map(int, input().split()))
count=0
maxHi=1
for i in range(N):
    if Hlist[0] >= maxHi:
        count+=1
        maxHi=Hlist.pop(0)
    else:
        del Hlist[0]
print(count)