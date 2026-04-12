from decimal import *
import math
K,A,B=map(int,input().split())
if A>=K:
  print(1)
elif A-B>0:
  print(1+math.ceil(Decimal(K-A)/Decimal(A-B))*2)
else:
  print(-1)
