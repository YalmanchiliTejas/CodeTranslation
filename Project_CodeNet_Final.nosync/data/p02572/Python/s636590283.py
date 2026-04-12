n = int(input())
L = list(map(int,input().split()))

L = sorted(L,reverse=True)

#print(L)
t = 0
a = 0
for i in range(1,n):
    t += L[i-1]
    a += (t * L[i]) #% (10**9 + 7)
#    print(t,a)

print(a % (10**9 + 7))    
