N = int(input())
A_ls=list(map(int, input().split()))

a=(sum(A_ls))**2
b=0
for i in A_ls:
	b+=(i**2)

c=int((a-b)//2)
print(c%(10**9+7))
#print(b)

# 2darray [[0] * 4 for i in range(3)]
# import itertools

