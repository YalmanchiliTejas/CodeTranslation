N = int(input())
lis = list(map(int, input().split()))

cnt = 1
for i in range(1,N):
	if lis[i] >= max(lis[:i]):
		cnt = cnt + 1
print(cnt)