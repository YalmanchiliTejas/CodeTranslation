def halfandhalf(A,B,C,X,Y):
    if X >= Y:
        if A+B > 2*C:
            sum = min(C*2*Y + A*(X-Y), C*2*X)
        else:
            sum = A*X + B*Y
        
    else:
        if A+B > 2*C:
            sum = min(C*2*X + B*(Y-X), C*2*Y)
        else:
            sum = A*X + B*Y
    return sum




if __name__ == "__main__":
    A,B,C,X,Y = map(int, input().split())
    print(halfandhalf(A,B,C,X,Y))
    