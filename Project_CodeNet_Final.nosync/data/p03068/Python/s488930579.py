import numpy as np
  
input()
S = np.asarray(list(str(input())))
K = int(input())
s = S[K-1]
S[S!=s] = "*"
print("".join(S))