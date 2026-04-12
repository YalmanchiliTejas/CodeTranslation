def removewhite(l):
  return [item for item in l if all([c=="." for c in item])==False]

import numpy as np
[H,W]=list(map(int,input().split()))
a=[list(input()) for _ in range(H)]

a=np.array(removewhite(np.array(removewhite(a)).T.tolist()
                      )
          ).T.tolist()
[print("".join(l)) for l in a]

