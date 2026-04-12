N=int(input())
L=list(map(int,input().split()))
highest=0
ans=0
for l in L:
    if l>= highest:
        ans+=1
        highest=l

print(ans)

