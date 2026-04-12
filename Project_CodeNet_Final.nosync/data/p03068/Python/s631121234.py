n = int(input())
s = input()
k = int(input())

target = s[k - 1]
s_new = ''
for i in range(n):
    if s[i] != target:
        s_new += '*'
    else:
        s_new += s[i]
print(s_new)
