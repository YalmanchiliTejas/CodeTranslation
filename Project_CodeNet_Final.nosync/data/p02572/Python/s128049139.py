n=int(input())
lis=list(int(x) for x in input().split() )
ans=0
x=10**9+7
su=0
for i in range(len(lis)) :
    su=su+lis[i]
for i in lis :
    su=su-i
    ans=(ans+su*i)%x

print(ans)
