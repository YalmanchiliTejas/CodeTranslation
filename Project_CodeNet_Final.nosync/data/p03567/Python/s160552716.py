S=input()
f=True
for i in range( len(S)-1 ):
    if S[i] == 'A' and S[i+1] == 'C':
        f = False
        

if f:
    print('No')
else:
    print('Yes')
