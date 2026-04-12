S = str(input())
c = 0
for i in range(0, 3):
    if S[i] == S[0]:
        c += 1
if c == 3:
    print('No')
else:
    print('Yes')