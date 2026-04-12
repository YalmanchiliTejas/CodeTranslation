A,B,C,X,Y = map(int,input().split())

ab1 = A + B
ab1c = C*2
ans = 0
if ab1 > ab1c:
    mi = min(X,Y)
    for i in range(mi):
        ans += C*2

    if X > Y:
        for i in range(X-Y):
            ans += A
    else:
        for i in range(Y-X):
            ans += B
else:
    for i in range(X):
        ans += A
    for i in range(Y):
        ans += B

t = 0
ma = max(X,Y)
for i in range(ma):
    t +=C*2

if t < ans:
    print(t)
    exit()

print(ans)
