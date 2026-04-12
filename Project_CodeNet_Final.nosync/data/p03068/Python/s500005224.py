N=int(input())
S=input()
K=int(input())
Slist =list(S)
for i in range(N):
	if Slist[K-1] == Slist[i]:
		continue
	else:
		Slist[i]="*"
S = ''.join(Slist)
print(S)