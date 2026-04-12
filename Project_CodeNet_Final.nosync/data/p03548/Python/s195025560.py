""" AtCoder """

X, Y, Z = map(int, input().split())

ans = -1
while X >= Z:
    X -= Y + Z
    ans += 1


print(ans)
