N = int(input())
S = input()
K = int(input())

tmp = str(S[K-1])
l = []
for n,i in enumerate(S):
    if i==tmp:
        l.append(i)
    else:
        l.append('*')
print("".join(l))