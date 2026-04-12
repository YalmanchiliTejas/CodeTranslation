S=input()

f=-1

for i in range(len(S)-1):
    if S[i]=='A' and S[i+1]=='C':
        f=1

if f>0:
    print('Yes')
else:
    print('No')