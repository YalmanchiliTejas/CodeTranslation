N = int(input())
S = list(map(str, input()))
flg = 0

def f(a, b, c):
	if a == "S" and b == "S" and c == "o":
		return "S"
	elif a == "S" and b == "S" and c == "x":
		return "W"
	elif a == "S" and b == "W" and c == "o":
		return "W"
	elif a == "S" and b == "W" and c == "x":
		return "S"
	elif a == "W" and b == "S" and c == "o":
		return "W"
	elif a == "W" and b == "S" and c == "x":
		return "S"
	elif a == "W" and b == "W" and c == "o":
		return "S"
	else:
		return "W"

for first, second in [("S", "S"), ("S", "W"), ("W", "S"), ("W", "W"), ]:
	ans = [None] * N
	ans[0], ans[1] = first, second
	
	for i in range(1, N - 1):
		ans[i + 1] = f(ans[i - 1], ans[i], S[i])
		
	if f(ans[-2], ans[-1], S[-1]) == ans[0] and f(ans[-1], ans[0], S[0]) == ans[1]:
		flg = 1
		break
		
if flg:
	for a in ans:
		print(a, end = "")
else:
	print(-1)