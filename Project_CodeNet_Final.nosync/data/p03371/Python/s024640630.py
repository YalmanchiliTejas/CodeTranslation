def main():
    A,B,C,X,Y = map(int, input().split())

    max_c = max([X,Y]) * 2
    yen = [0 for _ in range(max_c+1)]
    for c in range(max_c+1):
        x = X - c//2
        if x < 0:
            x = 0
        y = Y - c//2
        if y < 0:
            y = 0
        yen[c] = x*A + y*B + c*C
    return min(yen)

if __name__ == '__main__':
    print(main())

