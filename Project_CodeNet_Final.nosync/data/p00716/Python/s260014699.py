def co(a):
    global y,c,d
    for _ in range(y):a+=int(a*c)-d
    return int(a)

def i(a):
    global y,c,d
    b=0
    for _ in range(y):
        b+=int(a*c)
        a-=d
    return int(a+b)

for _ in range(int(input())):
    m=0
    a=int(input());y=int(input())
    for _ in range(int(input())):
        b,c,d=map(float,input().split())
        m=max(m,co(a) if b==1 else i(a))
    print(m)