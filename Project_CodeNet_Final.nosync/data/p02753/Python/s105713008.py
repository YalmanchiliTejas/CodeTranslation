S = input()
if S[0] != S[1]:
    print('Yes')
elif S[1] != S[2]:
    print('Yes')
elif S[0] != S[2]:
    print('Yes')
else:
    print('No')