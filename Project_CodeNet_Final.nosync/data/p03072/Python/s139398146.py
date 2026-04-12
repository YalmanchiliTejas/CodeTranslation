n=int(input())
h=[int(i) for i in input().split()]

max_height=0
cnt=0
for height in h:
	if height>=max_height:
		cnt+=1
	max_height=max([max_height,height])

print(cnt)