x,y,z = (int(x) for x in input().split())
cnt = 0

while x >= y*cnt+z*(cnt+1):
	if x == y*cnt+z*(cnt+1):
		print(str(cnt))
		break
	cnt+=1
else:
	print(str(cnt-1))