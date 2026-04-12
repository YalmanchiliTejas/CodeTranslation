def solve():
    X, Y, Z = list(map(int, input().split()))
    rest_width = X
    rest_width -= Z
    print(rest_width//(Y+Z))

solve()