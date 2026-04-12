import math
X_Y_Z = list(map(int, input().split()))

print(math.floor((X_Y_Z[0] - X_Y_Z[2])/(X_Y_Z[1]+X_Y_Z[2])))