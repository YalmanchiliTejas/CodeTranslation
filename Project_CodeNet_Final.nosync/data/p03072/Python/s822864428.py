n=int(input())
h=[int(i) for i in input().split()]
ans=0
hh=[]
for i in h:
    hh.append(i)
    if i==max(hh):
        ans+=1
print(ans)