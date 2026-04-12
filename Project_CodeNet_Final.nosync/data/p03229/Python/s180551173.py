N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

l = A.pop()
r = A.pop(0)
ans = abs(l-r)
while A:
	tmp = [abs(l-A[0]),abs(l-A[-1]),abs(r-A[0]),abs(r-A[-1])]
	cond = tmp.index(max(tmp))

	if cond == 0:
		ans += tmp[0]
		l = A.pop(0)
	elif cond == 1:
		ans += tmp[1]
		l = A.pop()
	elif cond == 2:
		ans += tmp[2]
		r = A.pop(0)
	else:
		ans += tmp[3]
		r = A.pop()

print(ans)
