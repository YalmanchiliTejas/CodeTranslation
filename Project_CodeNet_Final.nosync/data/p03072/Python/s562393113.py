N = input()
H = [s for s in input().split()]
[int(x) for x in H]
HIEST = int(H[0])

COUNT = 0
for i in H:
	i = int(i)
	if i >= HIEST:
		HIEST = i
		COUNT = COUNT+1
print(COUNT)