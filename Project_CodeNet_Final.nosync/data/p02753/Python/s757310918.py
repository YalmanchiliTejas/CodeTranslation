s = list(input())
print("No" if all([e == 'A' for e in s]) or all([e == 'B' for e in s]) else "Yes")
