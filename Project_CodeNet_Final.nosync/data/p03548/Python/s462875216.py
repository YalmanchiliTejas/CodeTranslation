X,Y,Z = map(int,input().split())
n = X // (Y+Z)

if X % (Y+Z) < Z :
    print(n-1)
else:
    print(n)