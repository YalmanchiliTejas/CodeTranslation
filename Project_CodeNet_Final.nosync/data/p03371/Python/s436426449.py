A, B, C, X, Y = map(int, input().split())

MAX = max(X, Y)
MIN = 2*C*max(X, Y)
i = MAX
x=X
y=Y

while i > 0:
    tmpC = (MAX-i)*2*C
    total = (A*x)+(B*y)+tmpC
    if(MIN > total):
        MIN = total
    i-=1
    if(x!=0):
        x-=1
    if(y!=0):
        y-=1

print(MIN)
