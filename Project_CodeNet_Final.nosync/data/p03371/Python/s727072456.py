def main():
    A, B, C, X, Y = (int(i) for i in input().split())
    if(A + B) <= C *2:
        print(A * X + B * Y)

    else:
        value = 0
        value = min(X, Y) * C * 2
        if (X - Y) >0:
            min_value = min(int(X - Y)*A, abs(X-Y)*C*2)
        else:
            min_value = min(int(Y - X)*B, abs(X-Y)*C*2)

        print(value + min_value)
if __name__ == '__main__':
    main()