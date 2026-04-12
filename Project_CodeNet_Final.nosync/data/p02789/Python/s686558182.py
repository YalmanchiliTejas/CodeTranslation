import numpy as np

NM=np.array(input().split(" "))
N=NM[0]
M=NM[1]

if(N==M):
    print("Yes")
else:
    print("No")