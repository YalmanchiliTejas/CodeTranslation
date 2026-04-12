#N = (int(i) for i in input().split(" "))
N = int(input())
H = [int(i) for i in input().split(" ")]
maxH = 0
ans = 0
for h in H:
	if h >= maxH:
		ans+=1
		maxH = h
print(ans)