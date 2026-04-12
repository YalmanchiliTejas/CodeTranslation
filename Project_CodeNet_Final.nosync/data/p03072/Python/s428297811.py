n = input()
n=int(n)

h=[]
h.append(input().split())
ans =1
check_flag=0

for i in range(n):
	if i ==0:
		continue
	for  k in range(i):
		if int(h[0][i]) < int(h[0][k]):
			check_flag = 1
	if check_flag !=1:
		ans +=1
	check_flag=0
print(ans)