n = int(input())
s = input()
k = int(input())
a = s[k-1]
res = ''
for i in s:
    if i == a:
        res = ''.join([res, a])
    else: 
        res = ''.join([res, '*'])
print(res)