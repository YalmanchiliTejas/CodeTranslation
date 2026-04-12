N=input()
S=raw_input()
K=input()

nokoru=S[K-1]

ans=""
for i in range(N):
	if S[i]==nokoru:
		ans+=S[i]
	else:
		ans+="*"

print ans
