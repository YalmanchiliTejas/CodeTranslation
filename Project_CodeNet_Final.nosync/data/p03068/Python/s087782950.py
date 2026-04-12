n = int(input())
s = input()
i = int(input())
print(*[a if a == s[i-1] else '*' for a in s], sep='')
