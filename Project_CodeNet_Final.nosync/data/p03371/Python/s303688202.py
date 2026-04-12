import math
S = input().split(" ")

A = int(S[0])
B = int(S[1])
C = int(S[2])
X = int(S[3])
Y = int(S[4])

def calculate(a,b,c,x,y):


    base = min([x,y])

    values = []
    for index in range(base+1):
        tmp = 2 * C * index + a * (x - index) + b * (y - index)
        values.append(tmp)

    s2 = max([x,y]) * 2 * c
    values.append(s2)

    print(min(values))

calculate(A,B,C,X,Y)