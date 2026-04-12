n = int(input())
s = input()
k = int(input())

for a in s:
    print(a if a==s[k-1] else '*',end='')