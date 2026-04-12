from collections import Counter

C = Counter(input())

print(["No","Yes"]['A' in C and 'B' in C])