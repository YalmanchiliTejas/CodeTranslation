N = int(input())
S = input()
K = int(input())

list = []

for s in S:
    if s == S[K-1]:
        list.append(s)
    else:
        list.append('*')

print(''.join(list))