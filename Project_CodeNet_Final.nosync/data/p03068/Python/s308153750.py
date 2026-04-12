k = int( input())
s = list(str(input()))
n = int( input())
a = ""
  
for i in range(len(s)):
    if s[i] != s[n-1]:
        s[i] = "*"
    a+=(str(s[i]))
        
print(a)