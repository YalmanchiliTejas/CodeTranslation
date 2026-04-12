n = int(input())
hs = [int(i) for i in input().split()]
max = 0
cnt = 0
for i in hs:
	if i >= max:
		cnt += 1
		max = i
print(cnt)