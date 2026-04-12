n = int(input())
s = list(input())
k = int(input())
t = s[k-1]
for i in range(0,n) :
    if s[i] != t :
        s[i] = '*'
s = ''.join(s)
print(s)