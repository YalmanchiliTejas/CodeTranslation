n = int(input())
S = input()
k = int(input())
# print(S[k-1])
for s in S:
    if s != S[k-1]:
        print('*', end = '')
    else:
        print(s, end = '')