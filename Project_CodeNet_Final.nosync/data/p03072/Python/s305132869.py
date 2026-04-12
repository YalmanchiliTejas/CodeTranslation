n=int(input())
h=list(map(int,input().split()))
ans=1
max_h=h[0]
for i in range(n-1):
    if max_h<=h[i+1]:
        ans+=1
        max_h=h[i+1]
print(ans)