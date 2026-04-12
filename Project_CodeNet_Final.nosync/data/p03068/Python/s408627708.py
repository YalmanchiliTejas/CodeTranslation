n = int(input())
s = input()
k = int(input())

a = s[k - 1]

result = [a if s[i] == a else '*' for i in range(n)]
print(''.join(result))