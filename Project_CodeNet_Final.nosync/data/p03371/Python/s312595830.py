def main():
    A,B,C,X,Y = [int(x) for x in input().split()]
    ans = 0
    if A+B <= C*2:
        ans = A*X + B*Y
    else:
        if X<=Y:
            ans = C*X*2 + min(B,C*2)*(Y-X)
        elif X>Y:
            ans = C*Y*2 + min(A,C*2)*(X-Y)
    print(ans)

if __name__ == '__main__':
    main()