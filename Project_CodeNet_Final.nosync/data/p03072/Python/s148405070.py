N = int(input())
H = list(map(int,input().split()))

ans = 0
for i in range(N):
	a=0
	for j in range(i+1):
		if H[j] <= H[i]:
			a=a+1
		else:
			break
	if a == i+1:
		ans=ans+1

print(ans)
		