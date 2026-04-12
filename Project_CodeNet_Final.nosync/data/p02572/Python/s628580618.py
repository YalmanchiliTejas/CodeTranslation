n = int(input())

a = input().split()

for i in range(n):
    a[i] = int(a[i])

s = 0
ans = 0
for i in range(n):
	s+=a[i]
for i in range(n):
	s -= a[i]
	ans += a[i]*s

print(ans % (1000000007))