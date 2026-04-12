n = int(input())
a = [int(i) for i in input().split()]
s = sum(a)
ans = 0 
for i in range(n-1):
	s-=a[i]
	ans+=s*a[i]
print(ans%(10**9+7))