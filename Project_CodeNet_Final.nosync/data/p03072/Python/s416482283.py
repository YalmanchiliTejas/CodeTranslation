N=int(input())
H=list(map(int,input().split()))

h=0
cnt=0
for i in range(N):
	if H[i]>=h:
		cnt+=1
		h=H[i]
print(cnt)