if __name__ == '__main__':
	w,h = map(int,input().split())
	
	A = []
	for _ in range(w):
		cmd = input()
		if cmd.count(".") != len(cmd):
			A.append(cmd)

	B = []
	for i in range(h):
		st = ""
		for a in A:
			st += a[i]
		if st.count(".") != len(st):
			B.append(st)

	#元に戻す
	C = []
	w = len(B[0])
	for j in range(w):
		st = ""
		for b in B:
			st += b[j]
		C.append(st)

	for c in C:
		print(c)