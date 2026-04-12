# coding: utf-8
# Your code here!
n=int(input())
sw=[0 for i in range(n)]
ox=list(input())

def who(x):
    if sw[x-1]=="S":
        a=1
    else:
        a=-1
        
    if sw[x]=="S":
        b=1
    else:
        b=-1
    
    if ox[x]=="o":
        c=1
    else:
        c=-1
    
    if a*b*c==1:
        return "S"
    else:
        return "W"
   
        
start=[["S","S"],["S","W"],["W","S"],["W","W"]]
ans=-1

for i in range(4):
    sw[0],sw[-1]=start[i]
    tmp1=sw[-1]
    tmp2=sw[0]

    for j in range(n):
        sw[(j+1)%n]=who(j)

    if tmp1==sw[-1] and tmp2==sw[0]:
        ans="".join(sw)
    
print(ans)