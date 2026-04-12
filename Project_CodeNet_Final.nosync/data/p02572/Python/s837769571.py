n = int(input())
a = [int(x) for x in input().split()]
m = 1000000007
ans = 0

b = [0]
for i in range(1,n+1):
  b.append((a[i-1] + b[i-1]) % m)
#print(a,b)
           
for i in range(n):
	p = b[n] - b[i+1]
	p *= a[i]
	p = p % m
	ans += p
	ans = ans % m
print(ans)