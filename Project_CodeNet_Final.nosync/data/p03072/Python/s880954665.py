N=int(input())
H=[int(i) for i in input().split()]
ans=0
for i,h in enumerate(H):
    if all([h>=m for m in H[:i]]):
        ans+=1
print(ans)
