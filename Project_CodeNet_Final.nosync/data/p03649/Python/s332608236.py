N=int(input())
a=list(map(int,input().split()))

ans=0
cnt=0
B=[0 for i in range(N)]
for x in range(10**6):
    for i in range(N):
        if a[i]>=N:
            cnt+=a[i]//N
            B[i]+=a[i]//N
            a[i]%=N
    if cnt==0:
        print(ans)
        exit()
    else:
        ans+=cnt
        for j in range(N):
            a[j]+=(cnt-B[j])
        cnt=0
        B=[0 for k in range(N)]
print(ans)
    