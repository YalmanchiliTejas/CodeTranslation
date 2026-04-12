X, Y, Z = map(int, input().split())

length = Z
cnt = 0
while length <= X:
    length += Y + Z
    if length > X:
        break
    cnt += 1

print(cnt)
