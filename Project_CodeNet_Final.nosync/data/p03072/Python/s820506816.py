N=int(input())
ta= list(map(int,input().split()))
ans=1
check=0
a=N-2
for i in range(N):
    if(i==0): continue
    for j in range(N-a):
        if(ta[j]<=ta[i]):
            if(j==N-a-1):
                ans+=1
        else:
            check+=1
        if(check==1):
            break
    check=0
    a-=1
print(ans)