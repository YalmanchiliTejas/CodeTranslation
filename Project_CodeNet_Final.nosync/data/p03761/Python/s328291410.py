n = int(input())
S = [input() for i in range(n)]

alpha = "abcdefghijklmnopqrstuvwxyz"

count = [50]*26
for i, x in enumerate(alpha):
    for s in S:
        count[i] = min(count[i], s.count(x))
ans = []
for i, x in zip(count, alpha):
    ans.append(x*i)
print("".join(ans))
