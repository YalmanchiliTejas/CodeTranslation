R,G,B=input().split(" ")
r=int(R)
g=int(G)
b=int(B)
s=100*r+10*g+b
if s%4==0:
    print("YES")
else:
    print("NO")