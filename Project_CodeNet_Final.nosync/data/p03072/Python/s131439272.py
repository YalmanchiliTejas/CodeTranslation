n=int(input())
s=input().split(' ')
h=[]
for i in range(0,n):
	h.append(int(s[i]))
count=1
for i in range(1,n):
	my=h[i]
	highest=max(h[0:i])
	if my >= highest:
		count=count+1

print(count)