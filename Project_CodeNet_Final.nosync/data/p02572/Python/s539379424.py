n = int(input())
a = list(map(int, input().split()))

suma = 0

for i in range(n):
	suma += a[i]

for i in range(n):
	suma -= a[i]
	a[i] *= suma


sumall = 0
for i in range(n):
	sumall += a[i]

print(sumall % 1000000007)