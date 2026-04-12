N = int(input())
S = input()
K = int(input())

O = []
for s in S:
    if s != S[K-1]:
        O.append("*")
    else:
        O.append(s)

print("".join(O))