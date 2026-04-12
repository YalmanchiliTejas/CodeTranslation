n = int(input())
s = str(input())
k = int(input())

a = []
for i in s:
    
    if i != s[k-1]:
        a.append('*')
    else:
        a.append(i)

print(*[i for i in a],sep='')