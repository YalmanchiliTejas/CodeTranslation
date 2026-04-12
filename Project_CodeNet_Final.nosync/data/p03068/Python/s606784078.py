N=int(input())
S=str(input())
K=int(input())
target = S[K-1]
arr = ''
 
for i in range(N):
	if S[i]==target:
		arr+=target
	else:
		arr+=('*')
 
print(arr)