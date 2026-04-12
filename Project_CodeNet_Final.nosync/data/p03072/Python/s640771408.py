# coding: utf-8
# Your code here!
n=int(input())
l=input().split(" ")
L=[]
for i in l:
    t=int(i)
    L.append(t)
ans=0
for i in range(n):
    k=0
    while(k<=i):
        if(L[i]<L[k]):
            break
        
        if(k==i):
            ans+=1
        k+=1
print(ans)
    
