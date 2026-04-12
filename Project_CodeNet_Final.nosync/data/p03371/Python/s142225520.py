def solution():
    a, b, c, x, y = map(int, input().split())
    if x == y:
        print(min((a*x + b*y),(c*2*x)))
    elif x > y:
        print(min((a*x + b*y),(c*2*x),(a*max(x-y, 0) + (c*2*y))))
    else:
        print(min((a*x + b*y),(c*2*y),(b*max(y-x, 0) + (c*2*x))))

solution()
