H, W = map(int, input().split())

a_list = [list(input()) for i in range(H)]
result = a_list[:]
for i,aa in enumerate(a_list):
    if aa.count('.') == len(aa):
        result[i] = 1
result = [r for r in result if r != 1]

#print(result)
import numpy as np
T_result = np.array(result).T
result2 = T_result.tolist()
for i, aa in enumerate(result2):
    if aa.count('.') == len(aa):
        result2[i] = 1

result2 = [r for r in result2 if r != 1]
for r2 in np.array(result2).T.tolist():
    print(''.join(r2))