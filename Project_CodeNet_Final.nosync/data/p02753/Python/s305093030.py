S=input()
lens = len(S)
s = [S[i] for i in range(lens)]
a = ['A' for i in range(lens) if S[i]=='A']
b = ['B' for i in range(lens) if S[i]=='B']
if len(a)>0 and len(b)>0:
    print('Yes')
else:
    print('No')