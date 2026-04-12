n = int(input())
a = list(map(int,input().split()))
# (sum(a)^2 - sum(a^2))/2
p = 10**9 + 7
ts = 0
s = 0
for i in range(n):
	s += a[i]
	ts = (ts + pow(a[i], 2, p)) % p
s = s % p
print((pow(s, 2, p)-ts)*pow(2, p-2, p)%p)