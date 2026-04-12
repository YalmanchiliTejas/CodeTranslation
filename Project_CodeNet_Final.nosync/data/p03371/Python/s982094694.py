if __name__ == '__main__':
    A, B, C, X, Y = map(int, input().split())
    min_cost = 2*max(X, Y)*C
    for c in range(0, 2*pow(10, 5)+2, 2):
        a = X-c//2
        b = Y-c//2
        if a>=0 and b>=0:
            cost = A*a+b*B+C*c
            min_cost = min(cost, min_cost)
    print(min_cost)