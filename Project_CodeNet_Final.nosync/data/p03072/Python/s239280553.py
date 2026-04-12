n=int(input())
h=[int(x) for x in input().split()]
ans=0
maxhi_1=0
for hi in h:
    if maxhi_1<=hi:
        ans+=1
        maxhi_1=hi
print(ans)