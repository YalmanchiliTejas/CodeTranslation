input()
s = input()
n = int(input())
print(*[i if i==s[n-1] else "*" for i in s], sep='')