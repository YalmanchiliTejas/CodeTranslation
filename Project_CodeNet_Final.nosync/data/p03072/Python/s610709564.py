n = int(input())
l=list(map(int, input().split()))
count=1
for i in range(n-1):
	if l[0]<=l[1]:
		l.pop(0)
		count+=1
	else:
		l.pop(1)
print(count)