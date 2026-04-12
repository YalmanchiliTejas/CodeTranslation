input()
H = [int(i) for i in input().split()]
res = 0
tmp = 0
for h in H:
    if h>=tmp:
        res+=1
        tmp = h
print(res)