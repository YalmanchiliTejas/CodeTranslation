X, Y, Z = map(int, input().split())
ans = 1
while ans * (Y + Z) + Z <= X:
	ans += 1
print(ans - 1)
