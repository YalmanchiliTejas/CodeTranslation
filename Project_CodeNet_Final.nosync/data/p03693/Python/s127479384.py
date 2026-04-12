ss = input().split()
a = int(ss[0])*100 + int(ss[1]) * 10 + int(ss[2])
if(a%4 == 0) :
	print("YES")
else :
	print("NO")
