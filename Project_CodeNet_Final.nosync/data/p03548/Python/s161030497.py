X,Y,Z = [int(i) for i in input().split()]

N, mod = divmod(X, Y+Z)
if mod < Z:
    N -= 1
print(N)