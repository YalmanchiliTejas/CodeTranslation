n = int(input())
s = input()
k = int(input())

char = s[k-1]

return_ = []

for i in range(n):
    if s[i] != char:
        return_.append('*')
    else:
        return_.append(s[i])

print("".join(return_))