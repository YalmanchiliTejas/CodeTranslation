from collections import Counter
n = int(input())
if n == 1:
    s0 = list(input())
    s0.sort()
    print("".join(s0))
else:
    s0 = list(input())
    s1 = list(input())
    match = list((Counter(s0) & Counter(s1)).elements())
    for i in range(n-2):
        s = list(input())
        match = list((Counter(match) & Counter(s)).elements())
    match.sort()
    print("".join(match))