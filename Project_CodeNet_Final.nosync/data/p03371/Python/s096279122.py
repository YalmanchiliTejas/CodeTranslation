def main():
    A, B, C, X, Y = [int(i) for i in input().split()]
#    print(A, B, C, X, Y)
    if((A + B) < C*2):
        result = A*X + B*Y
    else:
        if(X < Y):
            result = X * C * 2
            rem = Y - X
            if(B < C*2):
                result += B * rem
            else:
                result += C * rem*2
        else:
            result = Y * C * 2
            rem = X - Y
            if(A < C*2):
                result += A * rem
            else:
                result += C * rem*2
    
    print(result)
    
if __name__=="__main__":
    main()