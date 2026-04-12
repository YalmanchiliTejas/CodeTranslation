N = int(input())
S = input()
K = int(input())
e = S[K-1]
ans = []
for c in S:
    if c != e:
        ans.append("*")
    else:
        ans.append(c)
print(*ans, sep='')