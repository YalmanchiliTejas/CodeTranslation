a=int(input())
b=list(map(int,input().split()))
ans=1
for i in range(1,a):
    if max(b[:i])<=b[i]:
        ans+=1
print(ans)