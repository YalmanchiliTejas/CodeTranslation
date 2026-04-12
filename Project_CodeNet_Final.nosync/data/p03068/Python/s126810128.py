n = int(input())
s = list(input())
k = int(input())
target = ['*' if i != s[k -1] else i for i in s]
print(''.join(target))