n = int(input())
s = input()
k = int(input())
for a in range(n) :
    if s[a] != s[k-1] :
        s = s[:a]+"*"+s[a+1:]
print(s)