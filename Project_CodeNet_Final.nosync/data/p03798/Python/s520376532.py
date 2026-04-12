N=int(input())
s=input()
g=0
def ki(a,b):
    global g
    l=[None]*N
    l[-2],l[-1]=a,b
    for i in range(-1,N-1):
        if l[i-1]==l[i] and s[i]=="o":
            l[i+1]=0
        elif l[i-1]!=l[i] and s[i]=="x":
            l[i+1]=0
        else:
            l[i+1]=1
    if l[-2]==a and l[-1]==b and g==0:
        g=1
        for i in l:
            print("W" if i else"S",end="")
ki(0,0)
ki(0,1)
ki(1,0)
ki(1,1)
if not g:
    print(-1)