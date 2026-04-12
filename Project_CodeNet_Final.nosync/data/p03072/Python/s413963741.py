n=int(input())
h=[int(i) for i in input().split()]
ans=0
memo=h[0]
for i in h:
    if i>=memo:
        ans+=1
    memo=max(memo,i)
print(ans)