n=int(input())
H=list(map(int,input().split()))
ans=0
cnt=0
for i in range(n):
    if H[i]>=cnt:
        ans+=1
        cnt=H[i]

print(ans)