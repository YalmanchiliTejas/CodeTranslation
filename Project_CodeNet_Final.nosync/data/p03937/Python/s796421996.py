H,W = map(int,input().split())
A = []
c = 0
O = "ossible"
P = "P" + O
I = "Imp" + O

for i in range(H):
    a = input()
    A.append(a)
    c += a.count("#")

if H+W-1==c:
    print(P)
else:
    print(I)
