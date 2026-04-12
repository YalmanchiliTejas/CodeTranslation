M = 10 ** 9 + 7

N = int(input())
A_list = list(map(int, input().split()))

total = sum(A_list)

m = 0
for i in range(N - 1):
	A = A_list[i]
	total -= A
	m = (m + A * total) % M

print(m)
