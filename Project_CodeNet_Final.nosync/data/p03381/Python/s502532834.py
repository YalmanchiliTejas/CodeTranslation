# coding: utf-8
# Your code here!

N=int(input())
A = list(map(int,input().split()))

a=sorted(A)
#print(a)
d=a[N//2]
c=a[N//2 -1]

for i in A:
    if i >= d:
        print(str(c))
    else:
        print(str(d))
