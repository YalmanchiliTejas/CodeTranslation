n  = int(input())
w = list(map(int,input().split()))
temp, ans = 0,0
for i in range(len(w)):
	if w[i] >= temp:
		temp = w[i]
		ans += 1
print(ans)