n=int(input())
li = list(map(int,input().split()))
ans=0
check=0
ans+=(sum(li))**2
for i in range(n):
    check+=li[i]**2
ans=ans-check
ans//=2
print(ans%((10**9)+7))