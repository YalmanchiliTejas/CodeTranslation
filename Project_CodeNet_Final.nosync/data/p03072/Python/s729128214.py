N=int(input())
H=list(map(int,input().split()))
ans=0
hM=1
for hi in H:
    hM=max(hM,hi)
    if hM==hi:
        ans+=1
print(ans)