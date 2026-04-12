
N=list(map(int,input().split()))
num=100*N[0]+10*N[1]+N[2]
if num%4==0:
    print("YES")
else:
    print("NO")