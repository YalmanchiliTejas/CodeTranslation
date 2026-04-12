a,b=map(int,input().split())
c=0
for i in range(a):
    c+=input().count("#")
print("Impossible"if c!=a+b-1else"Possible")