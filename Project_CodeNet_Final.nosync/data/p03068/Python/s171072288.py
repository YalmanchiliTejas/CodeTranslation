N = int(input())
S = input()
K = int(input())
l = []
for i in S:
    if i == S[K-1]:
        l.append(i)
    else:
        l.append('*')

print(''.join(l))