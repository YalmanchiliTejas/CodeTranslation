S = input()

ans = True
if S.count('A') == 3 or S.count('B') == 3:
    ans = False

print('Yes' if ans else 'No')
