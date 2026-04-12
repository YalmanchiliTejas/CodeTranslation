n = int(input())
s = input()
k = int(input())
print(''.join([x if s[k-1] == x else '*' for x in s]))
