n = int(input())
data = list(map(int,input().split()))
h = 0
ans = 0
for i in range(n):
	if data[i]>=h:
		ans+=1
		h = data[i]
print(ans);