n=int(input())
U=[n-1-i for i in range(n)]
ind='0'+str(n)+'b'

for i in range(2**n):
    compare=[int(j) for j in format(i,ind)]
    disp=[U[j] for j in range(n) if compare[j]==1]
    disp.reverse()
    print(i,end=":")
    if len(disp)!=0:
        print(" "+' '.join(map(str,disp)),end="")
    print()

