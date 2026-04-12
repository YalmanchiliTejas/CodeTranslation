n = int(input())
h = list(map(int,input().split()))
tmp = 0
ans = 0
for i in h:
	if i >= tmp:
		tmp = i
		ans += 1
print(ans)