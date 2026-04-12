n=int(input())
h=input().split()
h=[int(h[i]) for i  in range(n)]

ans=0
for i in range(len(h)):
    if i == 0:
        ans+=1
    else:
        high=max(h[:i])
        if h[i]>=high:
            ans+=1

print(ans)