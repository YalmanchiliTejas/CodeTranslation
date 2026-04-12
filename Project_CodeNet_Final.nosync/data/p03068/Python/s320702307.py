n = int(input())
s = input()
k = int(input())

ss = s[k-1]

new_s = []

for i in range(n):
    if s[i] != ss:
        new_s.append('*')
    else:
        new_s.append(ss)

print(''.join(new_s))