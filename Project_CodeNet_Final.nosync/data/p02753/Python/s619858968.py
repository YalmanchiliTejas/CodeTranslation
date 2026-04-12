S = input()
k = []
for i in range(len(S)):
    k.append(S[i])
p = set(k)
L = list(p)
if len(L) == 1:
    print("No")
else:
    print("Yes")