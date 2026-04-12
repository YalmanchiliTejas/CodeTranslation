n = int(input())
s = input()
k = int(input())

l_s = list(s)
for i in range(n):
    if not l_s[i] == l_s[k-1]:
        l_s[i] = '*'
print(''.join(l_s))
