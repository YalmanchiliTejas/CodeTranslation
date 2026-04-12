n=int(input())
h=[int(i) for i in input().split()]

p=h[0]
ans=0

for i in h:
    if i>=p:
        ans+=1
        p=i

print(ans)