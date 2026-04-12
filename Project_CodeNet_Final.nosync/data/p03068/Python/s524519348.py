N = int(input())
S = str(input())
K = int(input())
s =[]
for i in range(len(S)):
    if S[i] ==S[K-1]:
        s.append(S[i])
    else:
        s.append('*')
print(''.join(s))