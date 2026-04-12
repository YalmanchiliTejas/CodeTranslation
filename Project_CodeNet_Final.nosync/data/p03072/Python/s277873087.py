n=int(input())
h=list(map(int,input().split()))
ans=1
for j in range(1,n):
    # print(j)
    if h[j-1]<=h[j]:
        if h[0]>h[j]:
            pass
        elif max(h[:j])<=h[j]:
            ans=ans+1 
        # print(h[j])
print(ans)