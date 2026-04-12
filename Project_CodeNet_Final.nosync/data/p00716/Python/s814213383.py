def c(a):
    global y,r,d
    for _ in range(y):a+=int(a*r)-d
    return a

def s(a):
    global y,r,d
    b=0
    for _ in range(y):
        b+=int(a*r)
        a-=d
    return a+b

for _ in range(int(input())):
    m=0
    a=int(input());y=int(input())
    for _ in range(int(input())):
        b,r,d=map(float,input().split())
        m=max(m,c(a) if b==1 else s(a))
    print(int(m))