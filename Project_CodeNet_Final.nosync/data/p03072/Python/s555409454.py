n = int(input())
h = list(map(int,input().split()))
yama = h[0]
umi = 1

for i in range(1,n):
	if h[i] >= yama:
		umi += 1
		yama = max(yama,h[i])
print(umi)