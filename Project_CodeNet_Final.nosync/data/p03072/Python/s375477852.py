n=int(input())
height=list(map(int,input().split()))
cont=1
temp=height[0]

for i in range(n):
	if i!=0 and height[i]>=temp:
		cont+=1
		temp=height[i]
print(cont)