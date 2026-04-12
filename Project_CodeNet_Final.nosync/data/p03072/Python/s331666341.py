N=int(input())
H=list(map(int,input().split()))

sums = 0
maxv = 0
for h in H:
    if maxv <= h:
        sums += 1
        maxv = h
print(sums)