N = int(input())
H = list(map(int,input().split()))
ans = 0
maxm = 0
for h in H:
	if maxm <= h:
		ans += 1
		maxm = h
print(ans)