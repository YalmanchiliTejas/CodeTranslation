n = int(input())
s = input()
k = int(input())

exa = s[k-1]
for i in s:
    if i != exa:
        s = s.replace(i,'*')
    
print(s)