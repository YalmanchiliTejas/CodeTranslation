N=int(input())
H_list=list(map(int,input().split()))
sub = 0

for i in range(1, N):
	for j in range(0, i):
		if H_list[i] < H_list[j]:
			sub += 1
			break
			
print(N - sub)