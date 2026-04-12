n=int(input())
data=list(map(int,input().split()))
count=0
hi=0
for h in data:
    if h>=hi:
        count+=1
    hi=max(hi,h)
print(count)

