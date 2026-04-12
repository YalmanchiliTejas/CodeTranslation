N,M=map(int,input().split())

ab=[list(map(int,input().split())) for i in range(M)]

ans=0
stack=[]

for i in ab:
    if i[0]==1:
        stack.append([i[1],1+2**(i[1]-1)])

while len(stack)>0:
    p=stack.pop()

    if p[1]==2**N-1:
        ans+=1
    else:
        for i in ab:
            if i[0]==p[0] and not(2**(i[1]-1)&p[1]):
                stack.append([i[1],p[1]+2**(i[1]-1)])
            if i[1]==p[0] and not(2**(i[0]-1)&p[1]):
                stack.append([i[0],p[1]+2**(i[0]-1)])

print(ans)
