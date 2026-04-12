#[int(i) for i in input().split()]
P = 1000000007
n = int(input())
a = [int(i) for i in input().split()]
pref = [0]*n
pref[n-1] = a[n-1]
for i in range(n-2,-1,-1):
	pref[i] = pref[i+1]+a[i]

ans = 0
for i in range(n-1):
	ans = (ans + (a[i] * pref[i+1]) % P)%P
print(ans)
