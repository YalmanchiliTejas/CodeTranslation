N=int(input())
H=list(map(int,input().split()))

ans = 0
curMax = 0
for h in H:
	if curMax <= h:
		ans += 1
	curMax = max(h,curMax)

print(ans)
