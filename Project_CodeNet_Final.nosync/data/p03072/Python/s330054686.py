n=map(int, input())
hs=list(map(int, input().split()))

max=0
count=0
for h in hs:
    if max <= h:
        count+=1
        max=h

print(count)