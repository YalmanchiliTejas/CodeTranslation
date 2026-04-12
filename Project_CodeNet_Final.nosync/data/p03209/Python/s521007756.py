
# This src was written after reading editional.pdf .

n, x = map(int, input().split())


an, pn = [1], [1]

for i in range(n):
    an.append(2*an[i]+3)
    pn.append(2*pn[i]+1)

#print(an)

def f(n,x):

    #print(n,x)

    if n == 0:
        return 1 if 0<x else 0
    
    if x <= an[ n-1 ] + 1:
        return f( n-1, x-1 )

    else:# x <= 2*an[n-1] + 3:
        return f(n-1, x-an[n-1]-2) + pn[n-1] + 1


print(f(n,x))

    
#    else if: 
#        pass