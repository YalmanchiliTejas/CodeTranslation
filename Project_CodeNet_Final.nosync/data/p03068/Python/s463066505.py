N = int(input())
S = list(input())
K = int(input())

char = S[K-1]
lst = []
for s in S:
    if s == char:
        lst.append(char)
    else:
        lst.append('*')

print(''.join(lst))