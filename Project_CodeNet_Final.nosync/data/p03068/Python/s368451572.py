import collections
n = int(input())
a = list(input())
k = int(input())

for i in range(n):
	if a[i] != a[k-1]:
		a[i] = "*"
print("".join(a))
