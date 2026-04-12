from collections import Counter

h, w = list(map(int, input().split()))
num = sum(Counter(input())['#'] for _ in range(h))
print('Possible' if w + h - 1 == num else 'Impossible')
