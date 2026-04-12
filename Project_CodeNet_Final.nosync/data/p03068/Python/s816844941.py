N = input()
S = input()
K = input()
result = []

target = S[int(K) - 1]

stringlist = list(S)
for i in stringlist:
    if target != i:
        result.append("*")
    else:
        result.append(i)

print("".join(result))