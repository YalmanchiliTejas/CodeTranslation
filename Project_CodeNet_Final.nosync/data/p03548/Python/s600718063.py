import sys
import math
 
# 入力
a, b, c = map(int, input().split())
# 計算
if a < (b + 2*c):
    print("a >= b + 2*cとなるようにしてください")
    sys.exit()
elif a == (b + 2*c):
    print("1")
else:
    max = math.floor((a - c) / (b + c))
    print(max)

    
