n = int(input())
a = [int(i) for i in input().split()]
d = []
cnt = 0
ans = 0
for i in range(n-1,0,-1):
	cnt+=a[i]
	d.append(cnt)
d = d[::-1]
for i in range(n-1):
	ans+=d[i]*a[i]
print(ans%(10**9+7))