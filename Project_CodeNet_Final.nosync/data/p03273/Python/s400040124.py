H,W=map(int,input().split())
A=[]
for _ in range(H):
    a=list(input())
    if("#" in a):
        A.append(a)
answer=[]
for i in range(W):
    tmp=[]
    hantei=True
    for a in A:
        if(a[i]=="#"):
            hantei=False
        tmp.append(a[i])
    if(hantei==False):
        answer.append(tmp)

result = list(zip(*answer))
for r in result:
    print("".join(r))