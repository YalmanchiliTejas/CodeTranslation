S = input()

for i,s in enumerate(S):
    if s == 'A':
        if i != len(S) and S[i+1] == 'C':
            print('Yes')
            break

else:
    print('No')
