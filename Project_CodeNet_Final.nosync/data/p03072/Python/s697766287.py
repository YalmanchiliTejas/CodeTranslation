n=int(input())
l=[int(_) for _ in input().split()]
ans=1
for i in range(1,n):
    if max(l[:i])<=l[i]:
        ans+=1
print(ans)