N = int(input())
A = []
for i in input().split():
	A.append(int(i))

currentMax = A[0]

count = 0
for a in A:
	if a >= currentMax:
		count += 1
		currentMax = a
print(count)
