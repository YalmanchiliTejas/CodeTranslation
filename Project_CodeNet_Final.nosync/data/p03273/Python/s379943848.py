h,w=map(int,input().split())
masulist=[list(input()) for a in range(h)]
masulist2=[b for b in masulist if b.count("#")]
x=[b for b in list(zip(*masulist2)) if b.count("#")]
y=list(zip(*x))
for a in y:
    print("".join(a))