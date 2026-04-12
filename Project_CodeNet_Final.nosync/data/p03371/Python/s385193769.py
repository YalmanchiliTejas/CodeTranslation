def main():
    A, B, C, X, Y = map(int, input().split())
    AB = A+B
    cost = 0
    if 2*C <= AB:
        if X <= Y:
            return X * 2 * C + (Y-X) * min(2*C, B)
        else:
            return Y * 2 * C + (X-Y) * min(2*C, A)
    else:
        return X * A + Y * B

if __name__ == '__main__':
    print(main())
