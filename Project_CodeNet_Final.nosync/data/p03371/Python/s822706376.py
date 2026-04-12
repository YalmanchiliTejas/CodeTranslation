A, B, C, X, Y = map(int, input().split())

min = X if X < Y else Y
max = X if X > Y else Y
sub = X - Y

if A+B > 2*C:
    ch = 2*C
else:
    ch = A+B

m = ch * min

if sub > 0:
    m += sub * A
else:
    m += sub * B * (-1)
    
m_ = ch * max

if m_ > m:
    print(m)
else:
    print(m_)