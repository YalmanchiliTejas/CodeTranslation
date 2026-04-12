N = int(input())
H = list(map(int, input().split()))
cnt=1
for i in range(1, N):
	if  H[i] >= max([a for a in H[0:i]]) :
		cnt = cnt + 1
print(cnt)