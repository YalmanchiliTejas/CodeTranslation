n,x = (int(i) for i in input().split())
def pc(n,k):
	if n and k==1: return 0
	elif k==1: return 1
	elif k<2**(n+1)-1: return pc(n-1,k-1)
	elif k==2**(n+1)-1: return 2**n
	elif k<2**(n+2)-3: return 2**n+pc(n-1,k-2**(n+1)+1)
	else: return 2**(n+1)-1
print(pc(n,x))