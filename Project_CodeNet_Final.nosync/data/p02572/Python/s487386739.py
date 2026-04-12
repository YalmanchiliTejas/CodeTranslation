n=int(input())
aa=list(map(int,input().split()))
su=sum(aa)
new=[n**2 for n in aa]
sa=sum(new)
x=10**9+7
print((su**2-sa)//2%x)
sa