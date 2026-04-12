n=int(input())
hs=list(map(int,input().split()))
a=1
x=hs[0]
for h in hs[1:]:
    if h>=x:
        a+=1
        x=h
print(a)
