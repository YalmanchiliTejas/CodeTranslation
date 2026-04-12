from collections import Counter
n = int(input())
cm = Counter(input())
for _ in range(n-1):
    S = Counter(input())
    cm = cm & S
cm = sorted(list(cm.elements()))
print(''.join(cm))