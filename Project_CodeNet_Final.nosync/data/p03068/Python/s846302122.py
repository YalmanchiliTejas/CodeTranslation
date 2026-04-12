n = int(input())
s = input()
a = s[int(input()) - 1]
for i in range(n):
    print(s[i] if s[i] == a else '*', end = '')