def make(l,ai): # len(a)=2
    global N
    for i in range(2,N):
        ai.append(ai[i-2]==(ai[i-1]==l[i-1]))
    return ai

def check(l,ai):
    return ai[0]==(ai[-2]==(ai[-1]==l[-1])) and ai[1]==(ai[-1]==(ai[0]==l[0]))

N=int(input())
l=[c=='o' for c in input()]

f=False
a=[[True,True],[True,False],[False,True],[False,False]]
for ai in a:
    ai=make(l,ai)

f=False
for ai in a:
    if check(l,ai):
        for aij in ai:
            print('S' if aij else 'W',end='')
        f=True
        break
if not f:
    print(-1)