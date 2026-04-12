import sys

S = list(map(int,input().split()))

i=0
while(1):
	if S[1]*i+S[2]*(i+1)>S[0]:
		i-=1
		break
	i+=1
print(i)