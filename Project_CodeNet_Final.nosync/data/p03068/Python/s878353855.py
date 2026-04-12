N = int(input())
S = input()
K =int(input())
Kchar = S[K-1]
res = []

for c in S:
    if c == Kchar:
       res.append(c)
    else:
        res.append("*")

print("".join(res))
