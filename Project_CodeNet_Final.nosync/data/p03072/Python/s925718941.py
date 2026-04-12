import numpy as np
#入力
N = input()
A = input()
#入力値を取り出す
B = np.array(list(map(int,A.split( ))))
ans = 1
for i in range(1, len(B)):
    if(len(B[0:-i][B[0:-i] > B[-i]])>0):
        ans = ans
    else:
        ans = ans + 1
print(ans)