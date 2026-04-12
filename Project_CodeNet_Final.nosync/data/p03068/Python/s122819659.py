n = int(input())
s = input()
k = int(input())
L = []
for i in range(n):
    if s[i] != s[k-1]:
        L.append("*")
    else:
        L.append(s[i])
        
print("".join(L))