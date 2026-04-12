N=int(input())
S=([chr(ord('a') + i) for i in range(26)])
L=[float("inf")]*26
for i in range(N):
	x=input()
	for j in range (len(S)):
		L[j]=min(L[j],x.count(S[j]))
for i in range(len(S)):
	print(S[i]*L[i],end="")
print("")