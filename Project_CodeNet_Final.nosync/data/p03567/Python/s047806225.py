S = input()
ans = False
for i in range(len(S)-1):
    if S[i] + S[i+1] == 'AC':
        ans = True

if ans:
    print('Yes')
else:
    print('No')