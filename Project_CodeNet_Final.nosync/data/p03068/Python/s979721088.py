N = int(input())
S = input()
K = int(input())
t = S[K-1]
res = ""
for i in S:
    if i == t:
        res += t
    else:
        res += "*"
print(res)