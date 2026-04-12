n=input()
k=int(input())

n1,n2,n3=int(n[-1]),0,0
a1,a2,a3=9,0,0
for i in n[-2::-1]:
    i=int(i)
    if i!=0:
        n1,n2,n3=i+a1,(i-1)*a1+n1+a2,(i-1)*a2+n2+a3
    a1,a2,a3=9+a1,9*a1+a2,9*a2+a3
print([n1,n2,n3][k-1])
