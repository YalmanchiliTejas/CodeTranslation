from collections import Counter
N=int(input())
S = []
S = Counter(input())
for i in range(N-1):
    s = input()
    for k,v in S.items():
        S[k] = min(v, s.count(k))

keys = [k for k in S.keys()]
keys.sort()
print(''.join([k*S[k] for k in keys]))
