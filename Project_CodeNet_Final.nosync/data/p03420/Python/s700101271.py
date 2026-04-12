n,k= map(int, input().split())

if k==0:
    print(pow(n,2))
    exit()

ans=0
# あまりの数で場合わけ
for i in range(k,n+1):
    ans+=n-i
    for j in range(1,int(pow(n-i,0.5))+1):
        ans+=max((n-i)//j-i,0)
        if j>i:
            ans+=max((n-i)//j-int(pow(n-i,0.5)),0)


print(ans)