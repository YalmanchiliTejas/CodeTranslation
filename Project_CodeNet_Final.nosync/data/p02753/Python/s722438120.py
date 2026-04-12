S = input()

s_len = len(S)

if S.count('A') == s_len:
    print('No')
    exit()
if S.count('B') == s_len:
    print('No')
    exit()

print('Yes')
