n = int(input())
s = input()
s = list(s)
k = int(input())
word = s[k-1]
for i in range(n):
    if s[i] != word:
        s[i] = "*"
print("".join(s))