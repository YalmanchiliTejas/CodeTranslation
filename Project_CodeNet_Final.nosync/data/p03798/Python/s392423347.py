n,s=open(0);n=int(n)
for a,b in ([0,0],[0,1],[1,0],[1,1]):
	r=[a,b]
	for i in range(n):a,b=b,s[-~i%n]=="xo"[a==b];r+=[b]
	if r[:2]==r[-2:]:print(*("WS"[i]for i in r[:-2]),sep="");exit()
print(-1)