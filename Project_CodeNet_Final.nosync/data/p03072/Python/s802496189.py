N=int(input())
H=list(map(int,input().split()))
now_h=H[0]
cnt=0
for i in range(N):
	if now_h<=H[i]:
		cnt+=1
		now_h=H[i]
print(cnt)