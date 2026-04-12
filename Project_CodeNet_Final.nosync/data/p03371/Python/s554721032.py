def main():
    (A,B,C,X,Y) = map(int,input().split())
    if X < Y:
        X, Y = Y, X
        A, B = B, A
    print(min(A + B, 2 * C) * Y + min(A, 2*C) * (X - Y))

main()
