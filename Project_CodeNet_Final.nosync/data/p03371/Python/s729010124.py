def main():
    A, B, C, X, Y = map(int, input().split())
    
    if A + B <= 2*C:
        print(A*X+B*Y)
    
    elif A + B > 2*C:
        cost = 0
        mi = min(X, Y)
        cost += 2*C*mi
        X -= mi
        Y -= mi
        
        if X > 0 and Y == 0:
            if A <= 2*C:
                cost += A*X
            else:
                cost += 2*C*X
        else:
            if B <= 2*C:
                cost += B*Y
            else:
                cost += 2*C*Y
        print(cost)
if __name__ == "__main__":
    main()