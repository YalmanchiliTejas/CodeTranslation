
n = int(input())
s = input()
k = int(input())

print(''.join([item if item == s[k-1] else '*' for item in s]))