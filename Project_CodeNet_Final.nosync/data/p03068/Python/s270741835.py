n = int(input())
s = input()
k = int(input())

rs = ''
for i in range(0, n):
    if s[i] != s[k-1]:
        rs += '*'
    else:
        rs += s[i]

print(rs)