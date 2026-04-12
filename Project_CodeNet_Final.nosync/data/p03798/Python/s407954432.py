def solve():
	n=int(input())
	s=[c=="o"for c in input()]
	for a,b in ([0,0],[0,1],[1,0],[1,1]):
		r=[a,b]
		for i in range(n):a,b=b,s[-~i%n]==(a==b);r+=[b]
		if r[:2]==r[-2:]:print("".join("WS"[i]for i in r[:-2]),sep="");exit()
	print(-1)
	
if __name__=="__main__":
	solve()