a,b, c = map(int, input().split())

A = a*100
B = b*10
C = A + B + c

if C % 4 == 0:
    print("YES")
else:
    print("NO")

