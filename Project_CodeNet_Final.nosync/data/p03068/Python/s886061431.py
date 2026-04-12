n = int(input())
s = list(input())
k = int(input())

a = s[k-1]

for i in range(n):
    if s[i] != a:
        print('*',end='')
    else:
        print(s[i],end='')

print()
    
