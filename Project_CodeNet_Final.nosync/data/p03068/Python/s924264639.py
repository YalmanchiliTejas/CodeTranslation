n = int(input())
s = list(input())
a = int(input())
b = s[a-1]
A = []
for i in s:
    if i != b:
        A.append("*")
    else:
        A.append(i)
print("".join(A))