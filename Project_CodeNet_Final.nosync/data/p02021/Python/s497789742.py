n=int(input())
ls=list(map(int,input().split()))
ans=0

for i in range(1,sum(ls)//n+1):
    am=0
    ans+=1
    for j in range(0,n-1):
        am=am+ls[j]-i
        if am<0:
            break
    else:
        continue
    if am!=0:
        ans=ans-1
    break

print(ans)

