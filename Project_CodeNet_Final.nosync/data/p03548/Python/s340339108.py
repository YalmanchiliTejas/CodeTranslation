def isu(X, Y, Z):
	#X > n * Y + (n+1) * Z = (X - Z) / (Y + Z) > n
	n_people = int((X - Z) / (Y + Z))
	print(n_people)

C = list(map(int,input().split()))
isu(C[0], C[1], C[2])