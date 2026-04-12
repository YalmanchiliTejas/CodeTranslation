# PROXY

N = int(input())
S = input().strip()
K = int(input())
newS = []
for elements in S:
    if S[K-1] != elements:
        elements = "*"
        newS.append(elements)
    else:
        newS.append(elements)
print("".join(newS))