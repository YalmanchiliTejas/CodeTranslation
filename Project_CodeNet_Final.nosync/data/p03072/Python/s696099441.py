def resolve():
	N=int(input())
	H=list(map(int,input().split()))
	mx=0
	cnt=0
	for i in H:
		if i>=mx:
			mx=i
			cnt+=1
	print(cnt)

resolve()