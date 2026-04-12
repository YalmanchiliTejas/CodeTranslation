N = int(input())
Hn = list(map(int,input().split()))

count = 1
for i in range(1,N):
	#print(Hn[:i],Hn[i])
	if max(Hn[:i]) <= Hn[i]:
		count += 1

print(count)