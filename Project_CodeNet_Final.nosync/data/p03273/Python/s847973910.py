H,W=map(int,input().split())

A=[0]*H
i=0
while i<H:
    A[i]=list(input())
    i+=1

B=[]
for i in A:
    if '#'in i:
        B.append(i)

j=W-1
while j>=0:
    if all(i[j]=='.' for i in B):
        k=0
        while k<len(B):
            B[k].pop(j)
            k+=1
    j-=1




for i in B:
    print(''.join(i))