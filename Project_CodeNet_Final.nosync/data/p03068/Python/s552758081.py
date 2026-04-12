n = int(input())
s = input()
k = int(input())

target = s[k - 1]
res = []
for alp in s:
    if alp == target:
        res.append(alp)
    else:
        res.append('*')

print(''.join(res))
