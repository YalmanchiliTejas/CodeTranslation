n = int(input())
s = str(input())
k = int(input())

t_word = s[k-1]
for i in s:
    if i != t_word:
        s = s.replace(i, "*")
print(s)