N=int(input())
S=input()
K=int(input())
s=S[K-1]
ans=str()
for i in S:
	if not i==s:
		ans+='*'
	else:
		ans+=i
print(ans)