from collections import Counter
from functools import reduce
#import numpy as np
N = int(input())
S = [[0]] * N
for n in range(N):
    S[n] = Counter(map(ord, input()))
#S = np.array(S)
#print(S)

def get_inter(counter1, counter2):
    dic = {}
    keys = counter1.keys() & counter2.keys()
    for key in keys:
        dic[key] = min(counter1[key], counter2[key])
    return dic

ans = ''
for key, value in reduce(get_inter, S).items():
    ans += chr(key) * value
print(ans)