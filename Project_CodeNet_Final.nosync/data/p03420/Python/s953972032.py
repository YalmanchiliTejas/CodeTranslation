# coding: utf-8
# Your code here!
N,K=[int(i) for i in input().split()]

num = 0
if K==0:
    print(N*N)
else:
    for b in range(K+1,N+1):
        num += (b-K)*(N//b) + max(0,N%b-(K-1))
    print(num)

#nnn=0
#for a in range(1,N+1):
#    for b in range(1,N+1):
#        if a%b >= K:
#            nnn+=1
#print(nnn)
            
