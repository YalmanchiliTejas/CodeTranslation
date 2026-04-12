

def solve(A, B, C, X, Y):
    if A + B < C*2:
        return A * X + B * Y

    paid = 0
    if A > C * 2:
        #print("A > 2C")
        # A を買うより、C を 2 枚かったほうがお得
        paid += X * 2 * C
        Y -= X
        X = 0
    
    if Y > 0:
        if B > C * 2:
            #print("B > 2C", Y)
            paid += Y * 2 * C
            X -= Y
            Y = 0
        
    if X <= 0 and Y <= 0:
        return paid

    Z = min(X, Y)
    paid += Z * 2 * C
    X -= Z
    Y -= Z

    if X > 0:
        paid += X * A
    if Y > 0:
        paid += Y * B

    return paid

    



A, B, C, X, Y = [int(x) for x in input().split()]
# X : required of A
# Y : required of B
# A, B, C <= 10^5
print(solve(A, B, C, X, Y))
