import numpy as np
import bisect

X , Y ,Z = input().split()
X = int(X)
Y = int(Y)
Z = int(Z)
x = X - Z
print(int(x / (Y + Z)))
