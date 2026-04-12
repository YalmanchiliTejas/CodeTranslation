# -*- coding: utf-8 -*-


from sys import stdin



############################################


# read data for n sequences.
n = stdin.readline()
N = int(n)
n = stdin.readline()
S = str(n)
n = stdin.readline()
K = int(n)
#data = [int(stdin.readline().rstrip()) for _ in range(n)]
key = S[K-1]

out=[]
for i,l in enumerate(S):
	if i < N:
		
		if l != key:
			out.append("*")
		elif l =="\n":
			x=1
		else:
			out.append(l)
out1=''
for o in out:
	out1+=o
print(out1)