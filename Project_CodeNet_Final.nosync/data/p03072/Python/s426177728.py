n = int(input())

arr = list(map(int,input().split()))

tmp = arr[0]
ans = 0

for i in range(n):
	if tmp <= arr[i]:
		ans += 1
		tmp = arr[i]

print(ans)
	