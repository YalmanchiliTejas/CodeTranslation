n = int(input())
s = input()
k = int(input())
l = []
a = ''

for i in range(n):
    l += s[i]

for i in range(n):
    if l[k-1] != l[i]:
        l[i] = '*'

for i in range(n):
    a += ''.join(l[i])
    
print(a)