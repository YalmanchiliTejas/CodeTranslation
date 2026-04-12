num = int(input())
N = list(map(int,input().split()))
cnt = 0
max = 0
for i in range(len(N)):
	if(max<=N[i]):
		cnt+=1
		max=N[i]
print(cnt)