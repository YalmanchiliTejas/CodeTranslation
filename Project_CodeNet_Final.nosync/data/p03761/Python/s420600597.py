from collections import Counter
n=int(input())
s=[input() for _ in range(n)]
sc=[Counter(s[i]) for i in range(n)]
alp="abcdefghijklmnopqrstuvwxyz"
alpm=[100 for _ in range(len(alp))]
ansl=[]
for q, i in enumerate(alp):
	for j in range(n):
		alpm[q] = min(alpm[q], sc[j][i])
for q in range(len(alp)):
	ansl.append(alp[q]*alpm[q])
print("".join(ansl))