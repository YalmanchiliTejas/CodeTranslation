X,Y,Z = list(map(int,input().split(" ")))
c = 0
for i in range(1,X):
    r = (Y * i) +(Z * (i+1))
    if r  > X:
        print(i-1)
        break