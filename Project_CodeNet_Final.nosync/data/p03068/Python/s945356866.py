n = int(input())
s = input()
k = int(input())
t = list(s)
u = ""
for i in range(n):
    if t[i]!=t[k-1]:
        t[i]="*"
for j in range(n):
    u = u+t[j]
print(u)