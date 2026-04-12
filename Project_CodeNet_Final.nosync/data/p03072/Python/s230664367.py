n = int(input())

arr = list(map(int,input().split(" ")))

mx,c = 0,0

for i in range(n):
	if(arr[i]>=mx):
		c += 1
		mx = arr[i]


print(c)