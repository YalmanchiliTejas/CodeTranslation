n = int(input())
s = input()
k = int(input())

ss = list(s)
chr = ss[k - 1]
for i in range(n):
    if ss[i] != chr:
        ss[i] = '*'
for i in range(n):
    print(ss[i], end = '')