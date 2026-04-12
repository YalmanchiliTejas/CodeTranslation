
n = int(input())

l = [int(x) for x in input().split()]

maxx = 0
cnt = 0

for i in range(n):
	if maxx <= l[i]:
		maxx = l[i]
		cnt += 1

print(cnt)