n = int(input())
a = [0 for i in range(26)]
b = [0 for i in range(26)]
S = input()
for i in S:
    a[ord(i) - 97] += 1
for i in range(n-1):
    T = input()
    for j in T:
        b[ord(j) - 97] += 1
    for j in range(26):
        a[j] = min(a[j],b[j])
    b = [0 for i in range(26)]
U = ""
for i in range(26):
    if a[i] != 0:
        U += chr(97+i)*a[i]
print(U)