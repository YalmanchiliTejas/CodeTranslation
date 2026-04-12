X, Y, Z = map(int, input().split())
cnt = 0
width = Z
while width <= X:
    width += Y + Z
    if width <= X:
        cnt += 1
else:
    print(cnt)