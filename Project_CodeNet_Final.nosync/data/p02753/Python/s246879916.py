S = input()

a = set()
for i in range(3):
    a.add(S[i])
if len(a) == 2:
    print('Yes')
else:
    print('No')