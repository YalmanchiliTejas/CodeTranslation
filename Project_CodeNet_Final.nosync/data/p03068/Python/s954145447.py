a=int(input())
s=list(input())	
r=int(input())

txt = s[r-1]
for i in range(len(s)):
    if(s[i] != txt):
        s[i] = "*"
s = ''.join(s)
print(s)