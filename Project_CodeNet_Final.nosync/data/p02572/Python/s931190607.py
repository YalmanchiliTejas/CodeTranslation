n = int(input())
a = list(map(int,input().split()))

mod = pow(10,9)+7

x = (sum(a)**2)%mod
y = 0
for i in range(n):
	y += (a[i]**2)%mod
print((x-y)*(pow(2,mod-2,mod))%mod)