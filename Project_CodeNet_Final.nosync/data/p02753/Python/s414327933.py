S = input()

f = S[0]
for s in S[1:]:
    if f != s:
        print('Yes')
        break
else:
    print('No')
