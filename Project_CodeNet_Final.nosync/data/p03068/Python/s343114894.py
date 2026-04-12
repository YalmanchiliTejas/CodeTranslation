n = int(input())
s = input()
k = int(input())
t = s[k - 1]
print(''.join(t if t == i else '*' for i in s))