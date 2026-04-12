X, Y, Z = map(int, input().split())

tmp_width = X - Z

print(tmp_width // (Y + Z))
