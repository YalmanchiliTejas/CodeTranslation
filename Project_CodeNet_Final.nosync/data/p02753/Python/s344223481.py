S = input()
ans = ''.join(set(S))
if len(ans) == 1:
    print('No')
else:
    print('Yes')
