'''input
5
9 5 6 8 4
'''
N=int(input())
H=list(map(int,input().split()))
count=1

for i in range(1,N):
	M=max(H[:i])
	if M<=H[i]:
		count+=1

print(count)