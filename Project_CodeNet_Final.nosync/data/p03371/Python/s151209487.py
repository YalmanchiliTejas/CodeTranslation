#-*-coding:utf-8-*-

def main():
    A, B, C, X, Y = list(map(int, input().split()))

    ABset = 2 * C
    min_price = 0

    #ABsetのほうがA,Bを個別に買うより安い場合
    if ABset <= A + B:
        if X >= Y:
            min_price += ABset * Y
            min_price += min(A * (X - Y), ABset * (X - Y))
        if X < Y:
            min_price += ABset * X
            min_price += min(B * (Y - X), ABset * (Y - X))
    else:
        min_price += A * X + B * Y

    print(min_price)

if __name__ == '__main__':
    main()