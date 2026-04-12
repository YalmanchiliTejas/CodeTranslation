N = int(input())
H = list(map(int,input().split()))
ans = 1
maxsofar = H[0]
for i in range(1,N):
	if H[i] >= maxsofar:
		ans += 1
		maxsofar = H[i]
print(ans)