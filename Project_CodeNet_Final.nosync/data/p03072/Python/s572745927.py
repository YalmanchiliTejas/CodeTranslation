n=int(input())
h=[int(i) for i in input().split()]

ans=0
max=h[0]
for i in h:
    if max <= i:
        ans+=1
        max=i

print(ans)

