n = int(input())
s = list(map(int, input().split()))

cnt = 0
max_s = 0

for i in range(n):
	if s[i] >= max_s:
		cnt += 1

	max_s = max(s[i],max_s)

print(cnt)

