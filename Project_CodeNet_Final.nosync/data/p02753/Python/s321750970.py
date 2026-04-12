S = input()

print('No' if all(s == 'A' for s in S) or all(s == 'B' for s in S) else 'Yes')
