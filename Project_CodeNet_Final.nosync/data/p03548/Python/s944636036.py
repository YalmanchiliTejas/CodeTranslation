X, Y, Z = map(int, input().split())
human = X // (Y + Z)
if (Y + Z) * human + Z > X:
    print(human - 1)
else:
    print(human)
