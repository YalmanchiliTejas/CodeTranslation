n = int(input())
s = input()
k = int(input())
out = []
for i in range(n):
    if s[i] == s[k-1]:
        out.append(s[k-1])
    else:
        out.append('*')
print(''.join(out))