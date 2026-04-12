n=int(input())
h=list(map(int, input().split()))
max_hi=0
ans=0
for i in range(len(h)):
    if max_hi<=h[i]:
        max_hi=h[i]
        ans+=1
print(ans)