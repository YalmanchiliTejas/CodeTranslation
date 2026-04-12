def main():
	S = input().split("/")
	if S[0] == "#":
		return
	for s in range(len(S)):
		for i in range(10):
			S[s]= S[s].replace(str(i),"."*i)
	a,b,c,d = map(int,input().split())
	S[a-1] = S[a-1][:b-1]+"."+S[a-1][b:]
	S[c-1] = S[c-1][:d-1]+"b"+S[c-1][d:]
	for s in range(len(S)):
		ref = ""
		temp = 0
		for i in S[s]:
			if i == ".":
				temp += 1
			else:
				ref += (str(temp) if temp is not 0 else "") + "b"
				temp = 0
		S[s] = ref + (str(temp) if temp is not 0 else "")
	print("/".join(S))
	main()
	return
main()
