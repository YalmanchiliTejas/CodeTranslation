n = int(input())
a = list(map(int, input().split()))
b = a.copy()
answer = 0
MOD = 10**9+7
for i in range(n-2, -1, -1):
	b[i] += b[i+1]

for i in range(n-1):
	answer = (answer+a[i]*b[i+1])%MOD
print(answer)