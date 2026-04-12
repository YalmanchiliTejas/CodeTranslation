n = int(input())
h = input().split()
max = 0
ans = []



for i in range(n):
	if max < int(h[i]) or max == int(h[i]):
		ans.append(int(h[i]))
		max = int(h[i])

print(len(ans))

