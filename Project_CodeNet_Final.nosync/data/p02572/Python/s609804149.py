n = int(input())
a = list(map(int,input().split()))
count = 0
su = sum(a)
for i in range(n-1):
	su -= a[i]
	count += a[i]*su
print(count%(10**9+7))