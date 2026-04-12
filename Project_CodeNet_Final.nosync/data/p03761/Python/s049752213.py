n = int(input())

arr = [[0 for i in range(n)] for j in range(26)]

for i in range(n):
	s = list(raw_input())
	for t in s:
		arr[ord(t) - ord("a")][i] += 1
ans = ''
for i in range(26):
	ans += chr(ord("a") + i) * min(arr[i])

print ans
