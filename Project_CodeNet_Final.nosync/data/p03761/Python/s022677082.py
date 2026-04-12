from string import ascii_lowercase
n = int(input())
ans_l = [100 for i in range(26)]
for i in range(n):
    s = str(input())
    for i, j in enumerate(ascii_lowercase):
        ans_l[i] = min(ans_l[i], s.count(j))
print("".join(i * j for i, j in zip(ascii_lowercase, ans_l)))
