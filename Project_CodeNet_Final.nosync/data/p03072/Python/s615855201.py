N = int(input())
arr = input().split()
num = 0
tmp = 0

for i in range(N):
	if int(arr[i]) >= tmp:
		num += 1
		tmp = int(arr[i])

print(num)
