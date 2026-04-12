n = int(input())
s = input().rstrip()
k = int(input())

target = s[k-1]
for i in range(n):
    if s[i] != target:
        s = s[:i] + "*" + s[i+1:]

print(s)