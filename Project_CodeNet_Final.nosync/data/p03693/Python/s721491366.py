p = input().split()
s = int(p[0])*100 + int(p[1])*10 + int(p[2])

if s % 4 == 0:
	print("YES")
else:
	print("NO")