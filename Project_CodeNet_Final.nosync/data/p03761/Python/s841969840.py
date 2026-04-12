n = int(input())
xs = [ input() for i in range(n)]

import string

def str2vec(xs):
    cs = [0] * len(string.ascii_lowercase)
    for x in xs:
        cs[ord(x) - ord('a')] += 1
    return cs
    
print("".join(map(lambda x: x[0]*x[1], zip(string.ascii_lowercase, map(min, zip(*map(str2vec, xs)))))))
