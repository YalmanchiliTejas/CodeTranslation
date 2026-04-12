n=int(input())
l=list(map(int,input().split()))
s=sum(l)
su=0
for i in range(n):
	s=s-l[i]
	s=s%1000000007
	su=su+(l[i]*s)
	su=su%1000000007
print(su)
	