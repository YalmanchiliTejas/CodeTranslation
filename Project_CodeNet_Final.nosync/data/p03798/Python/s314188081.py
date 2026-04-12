n=int(input())
s=input()
ss="SS"
sw="SW"
ws="WS"
ww="WW"
def f(t,c):
    if t=="o":
        if c[-2:]=="SS" or c[-2:]=="WW":
            return c+"S"
        else:
            return c+"W"
    else:
        if c[-2:]=="SW" or c[-2:]=="WS":
            return c+"S"
        else:
            return c+"W"
for i in s[1:n-1]:
    ss=f(i,ss)
    sw=f(i,sw)
    ws=f(i,ws)
    ww=f(i,ww)
def a(s,c):
    if f(s[-1],c[-2:])[2]!=c[0]:
        return 0
    if f(s[0],c[-1]+c[0])[2]!=c[1]:
        return 0
    return 1
for i in [ss,sw,ws,ww]:
    if a(s,i):
        print(i)
        break
else:
    print(-1)