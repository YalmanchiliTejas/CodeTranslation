n = int(input())
s = input()
k = int(input())

chk1 = s[k-1]

for i in range(len(s)):
    if s[i] != chk1:
        chk2 = s[i]
        s = s.replace(chk2,"*")
        
print(s)
