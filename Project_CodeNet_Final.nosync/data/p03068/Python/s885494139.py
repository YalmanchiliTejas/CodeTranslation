n = int(input())
s = input().rstrip()
k = int(input())

key = s[k-1]

for x in s:
    if x != key:
        s = s.replace(x, '*')
        
print(s)
    