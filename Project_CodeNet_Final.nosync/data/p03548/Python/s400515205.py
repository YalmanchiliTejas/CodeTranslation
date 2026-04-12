X, Y, Z = map(int, input().split())
p = X // (Y+Z)
if p*(Y+Z)+Z > X:
    p -= 1
print(p)