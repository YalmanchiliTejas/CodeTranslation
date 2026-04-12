n = int(input())
ls = [int(i) for i in input().split()]
maxx = ls[0]
inns = 0
for i in range(len(ls)):
    if ls[i] >= maxx:
        inns += 1
    if ls[i] > maxx:
        maxx =  ls[i]

print(inns)

