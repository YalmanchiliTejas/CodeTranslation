X, Y, Z = map(int, input().split())
ans = 1
length = Y+2*Z
while True:
    if length+Y+Z > X:
        print(ans)
        break
    ans += 1
    length += Y+Z

