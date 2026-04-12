n=int(input())
h=list(map(int, input().split()))
highest=0
ans=0
for i in range(n):
    if highest<=h[i]:
        highest=h[i]
        ans+=1
print(ans)