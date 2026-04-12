n=int(input())

l=list(map(int,input().split()))

summ=0

for i in l:
	summ+=i

ans=0
for i in l:
	summ-=i
	ans+=i*summ

print(ans%1000000007)