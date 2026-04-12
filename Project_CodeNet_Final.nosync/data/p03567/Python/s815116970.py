S = input()
f = False 
for i in range(len(S)-1):
    if S[i] == 'A'and S[i+1]=='C':
        f = True
        print("Yes")
        break;


if not f: 
    print("No")

