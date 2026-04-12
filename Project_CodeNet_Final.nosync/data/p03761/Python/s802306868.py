from collections import Counter
N = int(input())
S = Counter(input())
#print(S)
for _ in range(N-1):
    S &= Counter(input())

print("".join(sorted(S.elements())))
'''
sorted(S.elements())
Counter({'a': 2, 'c': 1})
['a', 'a', 'c']
'''