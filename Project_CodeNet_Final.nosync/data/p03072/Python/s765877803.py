n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
    for j in range(0,i):
        if h[j]>h[i]:
            break
    else:
        ans+=1
print(ans)