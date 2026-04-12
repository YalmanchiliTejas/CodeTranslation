rgb = list(input().split())
num = int("".join(rgb))
if num % 4 == 0:
	print("YES")
else:
	print("NO")