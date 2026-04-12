N=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(1,N):
    maxa=max(H[j] for j in range(i))
    if H[i]>=maxa:
        ans+=1
print(ans+1)