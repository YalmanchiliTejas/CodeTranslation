h,w=map(int,input().split())
a=[list(input()) for a in range(h)]
a2=[b for b in a if b.count("#")]
x=[b for b in list(zip(*a2)) if b.count("#")]
y=list(zip(*x))
for a in y:
    print("".join(a))