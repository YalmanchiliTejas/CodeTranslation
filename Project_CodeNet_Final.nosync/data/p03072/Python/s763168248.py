n=int(input())
l=list(map(int,input().split()))
cnt=0
ans=0
for i in range(n):
    cnt=max(cnt,l[i])
    if l[i]>=cnt:
        ans+=1
print(ans)