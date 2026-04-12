from collections import Counter
n = int(input())
alphabet = Counter(input())
for _ in range(n-1):
    counter = Counter(input())
    for i in range(26):
        alphabet[chr(i+97)] = min(alphabet[chr(i+97)], counter[chr(i+97)])
print(''.join(a*num for a, num in sorted(alphabet.items())))
