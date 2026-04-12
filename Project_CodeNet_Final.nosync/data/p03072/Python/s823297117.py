n=int(input())
lst=list(map(int, input().split()))
mh=lst[0]
ans=0
for i in lst:
    if(mh<=i):
        ans+=1
        mh=i
print(ans)
