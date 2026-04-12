N,X,M = [int(a) for a in input().split()]
amari = [0]*M
i = 1
A = X
amari[A] = i
l = [X]
ichi = i
while i<=M:
    i += 1
    A = A**2 % M
    if amari[A]: i += M
    else:
        amari[A] = i
        l.append(A)
    if i==N: i = M+1
else:
    if i>M+1: ni = i-M - amari[A]
    else: ni = 0
#for j in range(M):
#    if amari[j]: print(j, amari[j])
#print(i,len(l))
ichi = len(l) - ni
#print(l)
if ni:
    ni_times, san = divmod((N - ichi), ni)
    #print(ichi, '%d*%d'%(ni,ni_times), san)
    print(sum(l[:ichi]) + 
          sum(l[ichi:])*ni_times + 
          sum(l[ichi:ichi+san]))
else:
    #print(ichi, '%d*%d'%(ni,ni_times), san)
    print(sum(l))