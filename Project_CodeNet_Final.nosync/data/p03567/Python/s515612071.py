# Problem A - Can you get AC?

# input process
S = input()

# initialization
is_ok = False

# count process
for i in range(len(S)-1):
    if S[i]=='A' and S[i+1]=='C':
        is_ok = True
        break

if is_ok:
    print('Yes')
else:
    print('No')
