A,B,C,X,Y = map(int,input().split())
l = []
for i in range(max(X,Y)+1):
    T = i * C * 2
    if i < X: 
        T += (X-i)*A
    if i < Y:
        T += (Y-i)*B
    l.append(T)
l.sort()
print(l[0])