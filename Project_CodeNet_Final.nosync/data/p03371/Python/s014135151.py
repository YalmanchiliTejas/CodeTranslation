def main():
    A, B, C, X, Y = map(int, input().split())

    sum = 100000000000000000000000000000000
    for i in range(0, max(X,Y)*2+2, 2):
        if X-i//2 < 0 and Y-i//2 >= 0:
            sum = min(sum, B*(Y-i//2) + C*i)
        elif X-i//2 >= 0 and Y-i//2 < 0:
            sum = min(sum, A*(X-i//2) +C*i)
        else:
            sum = min(sum, A*(X-i//2) + B*(Y-i//2) + C*i)
    print(sum)

if __name__ == '__main__':
    main()