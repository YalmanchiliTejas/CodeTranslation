n=int(input())
h=[int(x) for x in input().split()]

max_h=h[0]

ans=1

for i in range(1,len(h)):
    if h[i] >= max_h:
        ans+=1
        max_h=h[i]

print(ans)
    