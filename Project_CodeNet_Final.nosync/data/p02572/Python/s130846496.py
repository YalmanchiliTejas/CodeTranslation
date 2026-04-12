def s():return int(input())
def mp():return map(int,input().split())
a = s()
b = list(mp())
ans=0
t = sum(b)%(10**9+7)
for i in range(a):
	t-=b[i]
	ans+=b[i]*t
	ans%=(10**9+7)
print(ans)