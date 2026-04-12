n = int(input())
s = input()
k = int(input())
keep = s[k-1]
print(''.join([x if x==keep else '*' for x in s]))