n = int(input())
s = input()
k = int(input())
sk = s[k-1]
ls = []
for i in s:
    ls.append(i)
for i in range(n):
    if ls[i] != sk:ls[i] = '*'
print(''.join(ls))