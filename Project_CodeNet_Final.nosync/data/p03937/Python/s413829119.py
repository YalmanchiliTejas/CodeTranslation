import numpy as np
H,W = map(int,input().split())
A = ""
for i in range(H):
  A+=input()
print("Possible" if A.count("#") ==H+W-1 else "Impossible")