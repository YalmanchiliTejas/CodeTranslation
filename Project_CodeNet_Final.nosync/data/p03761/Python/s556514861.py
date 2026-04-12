n = int(input())
s = [None] * n
for i in range(n):
    s[i] = input()

min_a = [50] * 26

alp = [chr(i) for i in range(97, 97+26)]

for i in range(n):
    a = [0] * 26

    for j in range(len(s[i])):
        for k in range(26):
            if s[i][j] == alp[k]:
                a[k] += 1

    for l in range(26):
        if min_a[l] > a[l]:
            min_a[l] = a[l]

sum = 0
for i in range(26):
    sum += min_a[i]

s = ""
for i in range(26):
    for j in range(min_a[i]):
        s += alp[i]

print(s)