n = int(input())
cn = n//2
lis = list(map(int,input().split()))
slis = sorted(lis)
if slis[cn-1] == slis[cn]:
	for i in range(len(lis)):
		print(slis[cn])
else:
	for item in lis:
		if item >= slis[cn]:
			print(slis[cn-1])
		else:
			print(slis[cn])