n=int(input())
l=[int(i) for i in input().split()]
ml=[0]
for i in l:
    res=ml[-1]
    if res<=i:
        ml.append(i)
    else:
        ml.append(res)
ans=0
for i in range(n):
    if ml[i+1]<=l[i]:
        ans+=1
print(ans)