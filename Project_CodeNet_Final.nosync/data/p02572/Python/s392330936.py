N=int(input())
s=[int(x) for x in input().split()]

area=sum(s)*sum(s)   
for i in s:
	area-=i*i
    
ans=area//2
ans=ans%(10**9+7)
print(ans)