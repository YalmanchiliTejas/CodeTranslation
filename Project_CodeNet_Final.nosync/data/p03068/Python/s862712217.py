n = int(input())
s = list(input())
k = int(input())

s2 = [["*", i][i == s[k-1]] for i in s]
print(("").join(s2))