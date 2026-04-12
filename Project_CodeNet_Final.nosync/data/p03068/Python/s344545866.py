n=int(input())
s=str(input())
k=int(input())

c = s[k-1]
s_d = ""

for i in range(n):
    if s[i]!=c:
        s_d += "*"
    else:
        s_d += s[i]
        
print(s_d)
