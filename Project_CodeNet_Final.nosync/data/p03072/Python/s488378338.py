N = int(input())
H = list(map(int,input().split(" ")))
ans = 0
higher = 0

for i in H:
	if higher <= i:
		higher = i
		ans += 1

print(ans)