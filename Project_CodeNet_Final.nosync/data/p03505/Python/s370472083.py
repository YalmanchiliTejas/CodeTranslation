# -*- coding: utf-8 -*-
k, a, b = list(map(int,input().split()))

d = a-b
if(a>=k):
    print(1)
elif(d<=0):
    print(-1)
else:
    if((k-a)%d == 0):
        print((2*(k-a)//d)+1)
    else:
        print((2*((k-a)//d+1))+1)