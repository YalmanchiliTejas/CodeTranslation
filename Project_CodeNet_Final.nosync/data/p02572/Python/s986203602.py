mod=1000000007
n=int(input())
c=list(map(int,input().split()))
m=sum(c)*sum(c)

g=0
for i in range(len(c)):
	g+=c[i]*c[i]

ll=(m-g)//2
ll=ll%mod
print(ll)
