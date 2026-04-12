l = []
n = int(input())
l = [int(i) for i in input().split()] 
ok = 0

for i in range(1,n):
	for j in range(i):
		if l[i] >= l[j]:
			if i -1 == j:
				ok += 1
			
		else:
			break

print(ok + 1)