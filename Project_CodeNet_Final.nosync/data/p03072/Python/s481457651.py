n = int(input())

arr = list(map(int, input().strip().split()))

ma = arr[0]
cnt = 1

for i in range(1,n):
	if arr[i] >= ma:
		cnt += 1

	ma = max(ma, arr[i])

print (cnt)