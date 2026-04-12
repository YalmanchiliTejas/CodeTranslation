S = input()
flag = False
for i in range(len(S)-1):
    if S[i:i+2] == 'AC':
        flag = True
        break
if flag:
    print('Yes')
else:
    print('No')
