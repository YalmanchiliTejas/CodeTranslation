N=int(input())
H=list(map(int,input().split()))
ans=0; mem=0
for i in H:
    if mem<=i: ans+=1
    mem=max(mem,i)
print(ans)