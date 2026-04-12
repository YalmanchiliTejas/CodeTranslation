line=input().split(" ")
a=int(line[0])
b=int(line[1])
c=int(line[2])
if (b*10+c)%4==0:
	print("YES")
else:
	print("NO")